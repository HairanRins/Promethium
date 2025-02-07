#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

struct Node {
    int vertex, weight;
    bool operator<(const Node& other) const {
        return weight > other.weight;
    }
};

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> distances(n, numeric_limits<int>::max());
    priority_queue<Node> pq;
    pq.push({start, 0});
    distances[start] = 0;

    while (!pq.empty()) {
        Node current = pq.top(); pq.pop();
        int u = current.vertex;
        if (current.weight > distances[u]) continue;
        for (auto& edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if (distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push({v, distances[v]});
            }
        }
    }
    return distances;
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 1}, {2, 4}},
        {{0, 1}, {2, 2}, {3, 6}},
        {{0, 4}, {1, 2}, {3, 3}},
        {{1, 6}, {2, 3}}
    };
    vector<int> result = dijkstra(graph, 0);
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
    return 0;
}