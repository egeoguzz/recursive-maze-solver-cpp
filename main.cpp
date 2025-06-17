#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 

using namespace std;

bool solveMaze(vector<vector<int> >& maze, int locX, int locY, int destinationX, int destinationY);
vector <vector<int> > readMazeFromFile(const string& filename, int& startX, int& startY, int& endX, int& endY);
void printMaze(const vector<vector<int>>& maze);
void printMazePretty(const vector<vector<int>>& maze, int startX = -1, int startY = -1);
void printBanner(const string& content);
void printEndCharacters();
void printLegend();

int main() {
    int startX, startY, endX, endY;
    vector<vector<int>> maze = readMazeFromFile("maze.txt", startX, startY, endX, endY);
    
    printBanner("Initial Maze");
    printMaze(maze);

    solveMaze(maze, startX, startY, endX, endY);

    printEndCharacters();
    printBanner("Solution Path");
    printMazePretty(maze, startX, startY);
    printLegend();
    printEndCharacters();

    return 0;
}

vector <vector<int> > readMazeFromFile(const string& filename, int& startX, int& startY, int& endX, int& endY) {
    vector <vector<int> > maze;
    ifstream file(filename);

    if (!file) {
        cerr << "Unable to open file " << filename << endl;
        exit(1);
    }

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

bool solveMaze(vector<vector<int>>& maze, int x, int y, int endX, int endY) {
    if (x == endX && y == endY) {
        maze[x][y] = 9;
        return true;
    }
    if (maze[x][y] != 0) return false;

    maze[x][y] = 2;

    if (x > 0 && solveMaze(maze, x - 1, y, endX, endY)) { maze[x][y] = 3; return true; }
    if (x + 1 < maze.size() && solveMaze(maze, x + 1, y, endX, endY)) { maze[x][y] = 3; return true; }
    if (y > 0 && solveMaze(maze, x, y - 1, endX, endY)) { maze[x][y] = 3; return true; }
    if (y + 1 < maze[0].size() && solveMaze(maze, x, y + 1, endX, endY)) { maze[x][y] = 3; return true; }

    maze[x][y] = 0; 
    return false;
}

void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
	cout << "               ";
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl; 
    }
}

void printMazePretty(const vector<vector<int>>& maze, int startX, int startY) {
    for (int i = 0; i < maze.size(); ++i) {
        cout << "               ";
        for (int j = 0; j < maze[i].size(); ++j) {
            if (i == startX && j == startY)
                cout << "S ";
            else {
                switch(maze[i][j]) {
                    case 3: cout << "X "; break;
                    case 9: cout << "E "; break;
                    default: cout << maze[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
}


void printBanner(const string& content) {
    const int width = 51;
    int padding = width - 4 - content.size(); 
    int left = padding / 2;
    int right = padding - left;

    cout << endl << string(width, '*') << endl;
    cout << "*"
         << string(left + 1, ' ') << content << string(right + 1, ' ') << "*"
         << endl;
    cout << string(width, '*') << endl << endl;
}

void printEndCharacters() {
    cout << endl << "####################################################" << endl << endl;
}

void printLegend() {
    cout << endl;
    cout << "Legend: S = Start   E = End   X = Solution Path   1 = Wall   0 = Open" << endl;
}

