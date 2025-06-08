# Recursive Maze Solver

This project is a simple maze solver implemented in C++ using recursion and backtracking techniques.

The maze is read from an external file named `maze.txt`, where:
- `0` represents an open path.
- `1` represents a wall.

## How to Run

1. Compile the code:

g++ -std=c++17 main.cpp -o maze-solver

2. Run the program:

./maze-solver

## Example maze.txt

```
0 1 0 0
0 1 0 1
0 0 0 1
1 1 0 0
```

## Features 

- Solves 2D mazes using recursion.
- Reads maze structure from a text file.
- Prints the solution path if exists.
- **Saves the solution path to an output file ('solution.txt).**
