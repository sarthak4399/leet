#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        // Create the graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        
        // Dijkstra's algorithm to find the shortest path distances
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Find the shortest path distances from n-1 to all nodes
        unordered_set<int> s;
        for (int i = n - 1; i > 0; i--) {
            s.insert(dist[i]);
        }
        
        // Check if each edge is part of at least one shortest path
        vector<bool> answer(edges.size(), false);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dist[u] + w + dist[v] == dist[n - 1] && s.count(dist[u]) && s.count(dist[v])) {
                answer[i] = true;
            }
        }
        
        return answer;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1,4},{0,2,1},{1,3,2},{1,4,3},{1,5,1},{2,3,1},{3,5,3},{4,5,2}};
    int n = 6;
    vector<bool> result = sol.findAnswer(n, edges);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << (result[i] ? "true" : "false") << (i == result.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;
    return 0;
}
