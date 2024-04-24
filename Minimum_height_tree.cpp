#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> graph(n);
//         for (const auto& edge : edges) {
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
//         for (int i = 0; i < n; ++i) {
//             cout << i << " -> ";

//             for (int j = 0; j < graph[i].size(); ++j) {
//                 cout << graph[i][j] << " ";
//             }
//             cout << endl;
//         }
//         if (edges.empty()) {
//             return {0};
//         }

//         vector<int> leaves;
//         for (int i = 0; i < n; ++i) {
//             if (graph[i].size() == 1) {
//                 leaves.push_back(i);
//             }
//         }
//         while (n > 2) {
//             n -= leaves.size();
//             vector<int> newLeaves;
//             for (int leaf : leaves) {
//                 int neighbor = graph[leaf][0];
//                 graph[neighbor].erase(std::find(graph[neighbor].begin(), graph[neighbor].end(), leaf));
//                 if (graph[neighbor].size() == 1) {
//                     if (std::find(newLeaves.begin(), newLeaves.end(), neighbor) == newLeaves.end()) {
//                         newLeaves.push_back(neighbor);
//                     }
//                 }
//             }
//             leaves = newLeaves;
//         }
//         return leaves;
//     }
// };
class Solution {
    public:
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            if (n == 1) {
                return {0};
            }
            if (n == 2) {
                return {0, 1};
            }
            vector<vector<int>> graph(n);
            vector<int> degree(n, 0);
            for (const auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
                degree[edge[0]]++;
                degree[edge[1]]++;

            }
            queue<int> q;
            for (int i = 0; i < n; ++i) {
                if (degree[i] == 1) {
                    q.push(i);
                }
            }
            while (n > 2) {
                int size = q.size();
                n -= size;
                for (int i = 0; i < size; ++i) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : graph[node]) {
                        degree[neighbor]--;
                        if (degree[neighbor] == 1) {
                            q.push(neighbor);
                        }
                    }
                }
            }
            vector<int> result;
            while (!q.empty()) {
                result.push_back(q.front());
                q.pop();
            }
            return result;
            
        }


};

int main () {
    Solution s;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}, {3, 4}, {4, 5}};
    vector<int> result = s.findMinHeightTrees(6 , edges);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    return 0;
}
