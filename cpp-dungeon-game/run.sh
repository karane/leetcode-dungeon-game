#!/bin/bash

# Usage check
if [ "$#" -ne 1 ]; then
    echo "Usage: ./run.sh <input_file>"
    exit 1
fi

INPUT_FILE="$1"
SRC_FILE="many_dungeons.cpp"
# SRC_FILE="many_dungeons _space_optimized.cpp"
EXE_FILE="dungeon_game"

# Compile the source file
echo "Compiling $SRC_FILE..."
g++ -std=c++11 "$SRC_FILE" -o "$EXE_FILE"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the executable with the provided input file
echo "Running $EXE_FILE with input from $INPUT_FILE..."
./"$EXE_FILE" "$INPUT_FILE"
