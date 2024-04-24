#include <iostream>
#include <vector>   

using namespace std;

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        //Create the graph
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
       
        vector<int> result;
        //Perform DFS traversal for each server
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            result.push_back(dfs(graph, i, signalSpeed, visited));
        }
        printGraph(graph);
        return result;
        
    }
private :
    void printGraph(const vector<vector<int>>& graph) {
        cout << "Graph:" << endl;
        for (int i = 0; i < graph.size(); ++i) {
            cout << i << " -> ";
            for (int j = 0; j < graph[i].size(); ++j) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
    //DFS traversal
    int dfs(vector<vector<int>>& graph, int source, int signalSpeed, vector<bool>& visited) {
        visited[source] = true;
        int count = 0;
        
        // Check if the distance from the source to each server is divisible by signalSpeed
        for (int neighbor : graph[source]) {
            if (!visited[neighbor] && (source < neighbor || neighbor == 0)) {
                if (dfs(graph, neighbor, signalSpeed, visited) % signalSpeed == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    vector<int> result = s.countPairsOfConnectableServers(edges, 2);
    
    // Returning the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
