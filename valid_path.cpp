#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        return (dfs(graph, source, destination, visited)) ;
    }

private:
    bool dfs(vector<vector<int>>& graph, int source, int destination, vector<bool>& visited) {
        if (source == destination) {
            return true;
        }
        visited[source] = true;
        for (int neighbor : graph[source]) {
            if (!visited[neighbor]) {
                if (dfs(graph, neighbor, destination, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    cout << s.validPath(3, edges, 0, 2) << endl; // Output: true
    return 0;
}
