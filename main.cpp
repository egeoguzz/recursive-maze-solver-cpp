#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void solveMaze(vector<vector<int> >& maze, int locX, int locY, int destinationX, int destinationY);
vector <vector<int> > readMazeFromFile(const string& filename);

int main() {
    vector <vector<int> > maze = readMazeFromFile("maze.txt");

    for (const auto& row: maze) {
        for (int cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    solveMaze(maze, 0,0, 3,3);

    return 0;
}

vector <vector<int> > readMazeFromFile(const string& filename) {
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

void solveMaze(vector<vector<int> >& maze, int locX, int locY, int destinationX, int destinationY) {
    int endX = maze.size();
    int endY = maze[0].size();
    if (locX == destinationX && locY == destinationY) {
	maze[locX][locY] = 9;
	cout << "done";
    }
	
    for (const auto& row: maze) {
        for (int cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    if (locX-1 >= 0 && maze[locX-1][locY] != 1 && maze[locX-1][locY] != 2) {
	cout << "x: " << locX-1 << endl << "y: " << locY << endl;
    	cout << "xxxxxxxxxxxxxxx" << endl;
	maze[locX][locY] = 2;
	solveMaze(maze, locX-1, locY, destinationX, destinationY);
    } 
    if (locX + 1 < endX && maze[locX+1][locY] != 1 && maze[locX+1][locY] != 2) {
	cout << "x: " << locX +1 << endl << "y: " << locY << endl;
    	cout << "xxxxxxxxxxxxxxx" << endl;
	maze[locX][locY] = 2;
	solveMaze(maze, locX +1, locY, destinationX, destinationY);
    }
    if (locY + 1 < endY && maze[locX][locY +1] != 1 && maze[locX][locY+1] != 2) {
	cout << "x: " << locX << endl << "y: " << locY +1 << endl;
    	cout << "xxxxxxxxxxxxxxx" << endl;
	maze[locX][locY] = 2;
	solveMaze(maze, locX, locY+1, destinationX, destinationY);
    } 
    if (locY - 1 >= 0 && maze[locX][locY-1] != 1 && maze[locX][locY-1] != 2) {
	cout << "x: " << locX << endl << "y: " << locY-1 << endl;
    	cout << "xxxxxxxxxxxxxxx" << endl;
	maze[locX][locY] = 2;
	solveMaze(maze, locX, locY-1, destinationX, destinationY);
    }
    
}

