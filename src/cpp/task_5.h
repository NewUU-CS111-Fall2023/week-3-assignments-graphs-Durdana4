#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TagGame {
public:
    TagGame(int n, int x) : n(n), x(x), adj_list(n + 1) {}

    void add_edge(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int calculate_moves() {
        vector<bool> visited(n + 1, false);
        vector<int> distance(n + 1, 0);

        stack<pair<int, int>> stk;
        stk.push(make_pair(x, 0));

        while (!stk.empty()) {
            int vertex = stk.top().first;
            int dist = stk.top().second;
            stk.pop();

            if (visited[vertex]) {
                continue;
            }

            visited[vertex] = true;
            distance[vertex] = dist;

            for (int neighbor : adj_list[vertex]) {
                stk.push(make_pair(neighbor, dist + 1));
            }
        }

        int max_distance = *max_element(distance.begin(), distance.end());
        return max_distance * 2;
    }

private:
    int n;
    int x;
    vector<vector<int>> adj_list;
};

int main() {
    int n, x;
    cin >> n >> x;

    TagGame game(n, x);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        game.add_edge(a, b);
    }

    int moves = game.calculate_moves();
    cout << moves << endl;

    return 0;
}