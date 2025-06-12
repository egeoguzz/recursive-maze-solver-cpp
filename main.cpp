#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 

using namespace std;

bool solveMaze(vector<vector<int> >& maze, int locX, int locY, int destinationX, int destinationY);
vector <vector<int> > readMazeFromFile(const string& filename, int& startX, int& startY, int& endX, int& endY);
void printMaze(const vector<vector<int>>& maze);

int main() {
    int startX, startY, endX, endY;
    vector<vector<int>> maze = readMazeFromFile("maze.txt", startX, startY, endX, endY);

    cout << "found" << startX << "," << startY << "," << endX << "," << endY << endl;
    for (const auto& row: maze) {
        for (int cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    solveMaze(maze, startX, startY, endX, endY);

    printMaze(maze);

    return 0;
}

vector <vector<int> > readMazeFromFile(const string& filename, int& startX, int& startY, int& endX, int& endY) {
    vector <vector<int> > maze;
    ifstream file(filename);

    if (!file) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }

    int num;
    while (!file.eof()) {
        vector <int> row;
        string line;
        getline(file, line);

        if (line.empty()) continue;

        if (line.find("START") == 0) {
            istringstream iss(line);
            string dummy;
            iss >> dummy >> startX >> startY;
            continue;
        }

	if (line.find("END") == 0) {
    	    istringstream iss(line);
    	    string dummy;
    	    iss >> dummy >> endX >> endY;
    	    continue;
	}

        for (char ch: line) {
            if (ch == '0' || ch == '1') {
                row.push_back(ch - '0');
            }
        }

        if (!row.empty()) {
            maze.push_back(row);
        }
    }

    file.close();
    return maze;
}

bool solveMaze(vector<vector<int> >& maze, int locX, int locY, int destinationX, int destinationY) {
    int endX = maze.size();
    int endY = maze[0].size();
    bool destinationReached = false;
    if (locX == destinationX && locY == destinationY) {
	maze[locX][locY] = 9;
	return true;
	cout << "done";
    }

    if (locX-1 >= 0 && maze[locX-1][locY] != 1 && maze[locX-1][locY] != 2) {
	cout << "x: " << locX-1 << endl << "y: " << locY << endl;
	maze[locX][locY] = 2;
	destinationReached = solveMaze(maze, locX-1, locY, destinationX, destinationY);
	if (destinationReached) {
	    maze[locX][locY] = 3;
	}
    } 
    if (locX + 1 < endX && maze[locX+1][locY] != 1 && maze[locX+1][locY] != 2) {
	cout << "x: " << locX +1 << endl << "y: " << locY << endl;
	maze[locX][locY] = 2;
	destinationReached = solveMaze(maze, locX +1, locY, destinationX, destinationY);
	if (destinationReached) {
	    maze[locX][locY] = 3;
	}
    }
    if (locY + 1 < endY && maze[locX][locY +1] != 1 && maze[locX][locY+1] != 2) {
	cout << "x: " << locX << endl << "y: " << locY +1 << endl;
	maze[locX][locY] = 2;
	destinationReached = solveMaze(maze, locX, locY+1, destinationX, destinationY);
	if (destinationReached) {
	    maze[locX][locY] = 3;
	}
    } 
    if (locY - 1 >= 0 && maze[locX][locY-1] != 1 && maze[locX][locY-1] != 2) {
	cout << "x: " << locX << endl << "y: " << locY-1 << endl;
	destinationReached = solveMaze(maze, locX, locY-1, destinationX, destinationY);
	if (destinationReached) {
	    maze[locX][locY] = 3;
	}
    }
    return destinationReached;
    
}

void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl; 
    }
}

