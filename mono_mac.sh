#!/bin/bash

SRC_DIR="./src"
OUT_DIR="./tmp"

mkdir -p $OUT_DIR

for cpp_file in $SRC_DIR/*.cpp; do
    file_name=$(basename "$cpp_file" .cpp)
    
    out_file="$OUT_DIR/${file_name}.out.cpp"
    
    mono ./actorcompiler.exe "$cpp_file" "$out_file"
    
    if [ $? -eq 0 ]; then
        echo "Processed $cpp_file successfully, output saved to $out_file"
    else
        echo "Failed to process $cpp_file"
    fi
done
