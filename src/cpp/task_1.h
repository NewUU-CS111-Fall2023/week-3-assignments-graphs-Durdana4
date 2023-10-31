/*
 * Author:
 * Date:
 * Name:
 */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class CityGraph {
private:
    int num_cities;
    vector<vector<int>> adj_list;
    int num_roads;
    int num_forbidden_triplets;

public:
    CityGraph(int num_cities, int num_roads, int num_forbidden_triplets) {
        this->num_cities = num_cities;
        this->adj_list.resize(num_cities + 1);
        this->num_roads = num_roads;
        this->num_forbidden_triplets = num_forbidden_triplets;
    }

    void add_road(int u, int v) {
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    pair<int, vector<int>> find_shortest_path(const vector<vector<int>>& forbidden_triplets) {
        vector<int> distances(num_cities + 1, INT_MAX);
        distances[1] = 0;

        vector<int> prev_city(num_cities + 1, -1);
        vector<bool> visited(num_cities + 1, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 1));

        while (!pq.empty()) {
            int dist = pq.top().first;
            int city = pq.top().second;
            pq.pop();

            if (visited[city])
                continue;

            visited[city] = true;

            for (int neighbor : adj_list[city]) {
                if (visited[neighbor])
                    continue;

                int new_dist = dist + 1;

                if (new_dist < distances[neighbor]) {
                    distances[neighbor] = new_dist;
                    prev_city[neighbor] = city;
                    pq.push(make_pair(new_dist, neighbor));
                }
            }
        }

        if (distances[num_cities] == INT_MAX)
            return make_pair(-1, vector<int>());

        for (const auto& triplet : forbidden_triplets) {
            int a = triplet[0], b = triplet[1], c = triplet[2];
            if (distances[a] + 1 == distances[b] && distances[b] + 1 == distances[c])
                return make_pair(-1, vector<int>());
        }

        vector<int> path;
        int curr_city = num_cities;
        while (curr_city != 1) {
            int prev = prev_city[curr_city];
            path.push_back(prev);
            curr_city = prev;
        }

        reverse(path.begin(), path.end());

        return make_pair(distances[num_cities], path);
    }
};

int main() {
    int n, m, k;
    cout << "Enter the number of cities, number of roads, and number of forbidden triplets: ";
    cin >> n >> m >> k;

    CityGraph graph(n, m, k);

    cout << "Enter the road descriptions:" << endl;
    for (int i = 0; i < m; i++) {
        int xi, yi;
        cin >> xi >> yi;
        graph.add_road(xi, yi);
    }

    vector<vector<int>> forbidden_triplets;
    cout << "Enter the forbidden triplets:" << endl;
    for (int i = 0; i < k; i++) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        forbidden_triplets.push_back({ai, bi, ci});
    }

    pair<int, vector<int>> shortest_path_info = graph.find_shortest_path(forbidden_triplets);

    if (shortest_path_info.first == -1) {
        cout << -1 << endl;
    } else {
        cout << "Shortest path length: " << shortest_path_info.first << endl;
        cout << "Shortest path: ";
        for (int city : shortest_path_info.second) {
            cout << city << " ";
        }
        cout << n << endl;
    }

    return 0;
}
