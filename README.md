# 🧩 Recursive Maze Solver (C++)

A simple, modern, and flexible **recursive maze solver** written in C++.  
Reads the maze from a `.txt` file, dynamically parses the **START** and **END** coordinates,  
and prints the solution path in a clean, visual format.

## 🚀 Features

- Reads maze and start/end coordinates from a file
- Recursive backtracking algorithm
- Clearly marks the solution path
- Handles any size rectangular maze
- User-friendly, clean output

---

## 📥 Input Format

The maze is provided as a plain text file.  
**Example (`maze.txt`):**
```
START 0 0
0 1 0 0
0 1 0 1
0 0 0 1
1 1 0 0
END 3 3
```

- **START x y:** Start position (row, column)
- **END x y:** End/goal position (row, column)
- **0:** Open path
- **1:** Wall/obstacle

*You can use any size and shape of maze, as long as the format matches.*

---

## 🛠️ How to Use

1. **Clone this repo**
2. **Create your `maze.txt` input file** (see above for format)
3. **Compile and run:**

```bash
g++ -std=c++11 -o maze_solver maze_solver.cpp
./maze_solver

Make sure maze.txt is in the same directory.

🖨️ Sample Output

X 1 0 0
X 1 0 1
X X X 1
1 1 X E

X: Solution path

E: End point

1: Wall

0: Unvisited open cell

🧠 Implementation Highlights

Uses recursive backtracking to find a path from START to END

Avoids cycles and dead-ends by marking visited cells

Prints the maze with the solution path clearly highlighted

✨ Example Mazes
Simple Maze

START 0 0
0 1 0 0
0 1 0 1
0 0 0 1
1 1 0 0
END 3 3

START 0 0
0 1 1 1 1
0 0 0 1 0
1 1 0 1 0
1 1 0 0 0
1 1 1 1 0
END 3 2

by Ismail Ege Oguz


