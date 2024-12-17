#include <iostream>
#include <vector>
#include "flow/flow.h"
#include "flow/network.h"
#include "flow/IConnection.h"
#include "fdbrpc/FlowTransport.h"
#include "fdbrpc/fdbrpc.h"
#include "flow/TLSConfig.actor.g.h"

ACTOR Future<int> addNumbers(Future<int> x, int y) {
    int value = wait(x);
    return value + y;
}

int main() {
    auto tls = TLSConfig();
    g_network = newNet2(tls);

    // We compose our future chain.
    auto result1 = addNumbers(Future<int>(10),5);

    // Tell the network when it can stop: wait for both future chains to complete.
    auto r = stopAfter(waitForAll(std::vector<Future<int>>({result1})));
    if (r.isError()) {
        std::cout << "Something bad happened: " << r.getError().what() << std::endl;
    }

    // Start the network and wait for it to stop.
    g_network->run();

    // Check and print the results.
    if (result1.isReady()) {
        std::cout << "Result 1: " << result1.getValue() << std::endl;
    } else {
        std::cout << "Failed!" << std::endl;
        return 1;
    }
}
