#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

int main() {
    vector <vector<int> > maze = readMazeFromFile("maze.txt");

    for (const auto& row: maze) {
        for (int cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}