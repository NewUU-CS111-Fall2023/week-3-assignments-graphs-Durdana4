#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MazeSolver {
public:
    MazeSolver(const vector<string>& maze) : maze(maze) {
        num_rows = maze.size();
        num_cols = maze[0].size();
        start = make_pair(-1, -1);
        treasure = make_pair(-1, -1);
    }

    bool solveMaze(int num_avoid_spikes) {
        findStartAndTreasure();

        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        return dfs(start.first, start.second, num_avoid_spikes, visited);
    }

private:
    const vector<string>& maze;
    int num_rows;
    int num_cols;
    pair<int, int> start;
    pair<int, int> treasure;

    bool dfs(int row, int col, int num_avoid_spikes, vector<vector<bool>>& visited) {
        if (make_pair(row, col) == treasure) {
            return true;
        }

        if (!isValidPosition(row, col) || visited[row][col]) {
            return false;
        }

        visited[row][col] = true;

        if (maze[row][col] == 's') {
            if (num_avoid_spikes > 0) {
                num_avoid_spikes--;
            } else {
                return false;
            }
        }

        vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (const auto& dir : directions) {
            if (dfs(row + dir.first, col + dir.second, num_avoid_spikes, visited)) {
                return true;
            }
        }

        return false;
    }

    bool isValidPosition(int row, int col) {
        return row >= 0 && row < num_rows && col >= 0 && col < num_cols && maze[row][col] != '#';
    }

    void findStartAndTreasure() {
        for (int i = 0; i < num_rows; i++) {
            for (int j = 0; j < num_cols; j++) {
                if (maze[i][j] == '@') {
                    start = make_pair(i, j);
                } else if (maze[i][j] == 'x') {
                    treasure = make_pair(i, j);
                }
            }
        }
    }
};

int main() {
    int n, m, j;
    cout << "Enter the number of rows, width of each row, and the number of times Jarmtin can avoid spikes: ";
    cin >> n >> m >> j;

    vector<string> maze;
    cout << "Enter the maze:" << endl;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        maze.push_back(row);
    }

    MazeSolver mazeSolver(maze);

    if (mazeSolver.solveMaze(j)) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
