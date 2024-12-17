# Class-Scheduling
## Steps:
    git clone git@github.com:gyming1849/flow_compile.git
    rm -rf flow_compile/Readme.md
    cp -r flow_compile/* .
    rm -rf src/*
    rm -rf flow_compile/

### Setting Up the Environment:
1. Make the script files executable:
    ```bash
    chmod +x mono_mac.sh
    chmod +x run.sh
    ```

2. Start the project:
    ```bash
    mkdir tmp
    ./run.sh
    ```

    You should see the following output:
    ```
    Docker container started successfully with ID: xxxx
    To connect to the container, use the following command:
    docker exec -it xxxx /bin/bash
    ```

### Accessing the Code

Your code files should be located in the `src` folder.

### Connecting to the Docker Container

Run the following command to connect to the Docker container:
```bash
docker exec -it xxxx /bin/bash
```

### Building the Project

1. Once inside the container, navigate to the build directory and compile the project:
    ```bash
    cd build
    cmake ..
    make
    ```

2. After running `make`, you will find the executable file in the `build` folder.

### Additional Instructions for Mac M-series Users

Before every build, execute the following script on your machine (not inside the container):
```bash
./mono_mac.sh
```
