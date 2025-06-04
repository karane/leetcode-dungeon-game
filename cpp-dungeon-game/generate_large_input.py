import random

RANGE_START = -50
RANGE_END = 30
MIN_DIMENSIONS = 100
MAX_DIMENSIONS = 1000
NUM_TESTS = 10
def generate_dungeon(rows, cols):
    return [[random.randint(RANGE_START, RANGE_END) for _ in range(cols)] for _ in range(rows)]

def main():
    filename = "large-input.txt"

    with open(filename, "w") as f:
        f.write(f"{NUM_TESTS}\n")

        for t in range(NUM_TESTS):
            rows = random.randint(MIN_DIMENSIONS, MAX_DIMENSIONS)
            cols = random.randint(MIN_DIMENSIONS, MAX_DIMENSIONS)
            f.write(f"{rows} {cols}\n")

            dungeon = generate_dungeon(rows, cols)
            for row in dungeon:
                f.write(" ".join(map(str, row)) + "\n")

            print(f"Test case #{t+1}: {rows}x{cols} dungeon written.")

    print(f"\nAll {NUM_TESTS} test cases written to {filename}.")

if __name__ == "__main__":
    main()
