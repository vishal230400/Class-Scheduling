#!/bin/bash

CURRENT_DIR=$(pwd)

IMAGE_NAME="gyming1850/flow_compile"

ARCH=$(uname -m)

DOCKER_RUN_OPTS="-d --mount type=bind,source=\"${CURRENT_DIR}/src\",target=\"/flow_compile/src\" --mount type=bind,source=\"${CURRENT_DIR}/tmp\",target=\"/flow_compile/tmp\""

if [ "$ARCH" == "arm64" ]; then
    DOCKER_RUN_OPTS="$DOCKER_RUN_OPTS --platform=\"linux/amd64\" -e SKIP_MONO=1"
fi

CONTAINER_ID=$(eval "docker run $DOCKER_RUN_OPTS ${IMAGE_NAME} tail -f /dev/null")

if [ -n "$CONTAINER_ID" ]; then
    echo "Docker container started successfully with ID: $CONTAINER_ID"
    echo "To connect to the container, use the following command:"
    echo "docker exec -it $CONTAINER_ID /bin/bash"
else
    echo "Failed to start Docker container."
fi
