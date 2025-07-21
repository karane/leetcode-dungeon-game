# Dungeon Game Solver

This project solves the "Dungeon Game" problem for multiple input cases, where each dungeon is a 2D grid of integers. Each test case determines the minimum health needed to reach the bottom-right corner of the dungeon safely.

---

## Prerequisites

Before running the script, ensure you have the following installed:

- **g++** (C++17 or later)
- **bash**
- **Python** (3.9 or later)

To check:
```bash
g++ --version
bash --version
```

### How to Use
1. Make run.sh executable
```bash
cd cpp-dungeon-game
chmod +x run.sh 
```

2. Run the script with the input file
```bash
./run.sh <INPUT FILE>
```

Example:
```bash
./run.sh input.txt
```

### How to generate large inputs

1. Run the input generator
```bash
cd cpp-dungeon-game
python3 generate_large_input.py
``` 

2. Run the script with the input file
```bash
./run.sh large-input.txt
```

## General Dynamic Programing Solution - Example

!(Default DP Solution)[./images/default-dp-solution.png]