#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> result(n, 0); // Stores the result
        vector<int> count(n, 1);  // Stores the count of nodes in each subtree
        vector<vector<int>> graph(n); // Graph representation

        // Creating graph representation
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // First DFS to calculate the count of nodes in each subtree
        dfs(0, -1, graph, count, result);

        // Second DFS to calculate the sum of distances for each node
        dfs2(0, -1, graph, count, result, n);

        return result;
    }

    // First DFS to calculate the count of nodes in each subtree
    void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& count, vector<int>& result) {
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, node, graph, count, result);
            count[node] += count[neighbor];
            result[node] += result[neighbor] + count[neighbor];
        }
    }

    // Second DFS to calculate the sum of distances for each node
    void dfs2(int node, int parent, vector<vector<int>>& graph, vector<int>& count, vector<int>& result, int n) {
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            result[neighbor] = result[node] - count[neighbor] + n - count[neighbor];
            dfs2(neighbor, node, graph, count, result, n);
        }
    }
};


int main (){
    Solution s;
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int> result = s.sumOfDistancesInTree(6, edges);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
