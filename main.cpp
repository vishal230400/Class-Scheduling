#define FDB_API_VERSION 630  // Use the appropriate API version for FoundationDB
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <foundationdb/fdb_c.h>

FDBDatabase *database;

// Function to abort the program on an error
void abort_on_error(fdb_error_t err) {
  if (err) {
    fprintf(stderr, "Error: %s\n", fdb_get_error(err));
    abort();
  }
}

// Network thread function
void *run_net(void *_unused) {
  abort_on_error(fdb_run_network());
  return NULL;
}

// Function to initialize the FoundationDB database
FDBDatabase *get_database(const char *cluster_file) {
  FDBDatabase *out;
  abort_on_error(fdb_create_database(cluster_file, &out));
  return out;
}

// Function to set a key-value pair and commit the transaction
void setValueAndCommit(const char *key, const char *value) {
  FDBTransaction *txn;
  printf("Creating transaction for set operation...\n");
  abort_on_error(fdb_database_create_transaction(database, &txn));

  printf("Setting key '%s' to value '%s'...\n", key, value);
  fdb_transaction_set(txn, (uint8_t *)key, strlen(key), (uint8_t *)value, strlen(value));

  printf("Committing transaction...\n");
  FDBFuture *cf = fdb_transaction_commit(txn);
  printf("Waiting for commit to complete...\n");
  abort_on_error(fdb_future_block_until_ready(cf));
  printf("Transaction committed successfully.\n");
  fdb_future_destroy(cf);

  fdb_transaction_destroy(txn);
}

// Function to retrieve the value for a given key
void getValue(const char *key) {
  FDBTransaction *txn;
  printf("Creating transaction for get operation...\n");
  abort_on_error(fdb_database_create_transaction(database, &txn));

  printf("Getting key '%s'...\n", key);
  FDBFuture *rf = fdb_transaction_get(txn, (uint8_t *)key, strlen(key), 0);

  printf("Waiting for get operation to complete...\n");
  abort_on_error(fdb_future_block_until_ready(rf));
  fdb_bool_t present;
  const uint8_t *out_value = NULL;
  int out_value_length;
  abort_on_error(fdb_future_get_value(rf, &present, &out_value, &out_value_length));
  fdb_future_destroy(rf);

  if (present) {
    printf("Value for key '%s' is '%.*s'\n", key, out_value_length, out_value);
  } else {
    printf("Key '%s' not found\n", key);
  }

  fdb_transaction_destroy(txn);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <path_to_fdb.cluster>\n", argv[0]);
    exit(1);
  }

  const char *clusterFilePath = argv[1];

  printf("Selecting FoundationDB API version %d...\n", FDB_API_VERSION);
  abort_on_error(fdb_select_api_version(FDB_API_VERSION));

  printf("Setting up FoundationDB network...\n");
  abort_on_error(fdb_setup_network());

  // Enable trace logging
  printf("Enabling trace logging...\n");
  abort_on_error(fdb_network_set_option(FDB_NET_OPTION_TRACE_ENABLE, 
                                        (uint8_t *)"/tmp/fdb_traces", 
                                        strlen("/tmp/fdb_traces")));

  pthread_t net_thread;
  printf("Starting network thread...\n");
  int rv = pthread_create(&net_thread, NULL, run_net, NULL);
  if (rv) {
    fprintf(stderr, "Error: Failed to create network thread.\n");
    exit(rv);
  }

  printf("Connecting to FoundationDB cluster using '%s'...\n", clusterFilePath);
  database = get_database(clusterFilePath);
  printf("Connected to FoundationDB cluster.\n");

  const char *key = "/fdbhello/test/value";
  const char *value = "hello world!";

  // Set the value of a key
  printf("\n--- Performing Set Operation ---\n");
  setValueAndCommit(key, value);

  // Get the value of the key
  printf("\n--- Performing Get Operation ---\n");
  getValue(key);

  // Clean up
  printf("\nCleaning up...\n");
  fdb_database_destroy(database);
  abort_on_error(fdb_stop_network());
  pthread_join(net_thread, NULL);

  printf("Program completed successfully.\n");
  return 0;
}
