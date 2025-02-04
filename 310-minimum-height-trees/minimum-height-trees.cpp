class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case where there's only one node

        vector<int> ans, indegree(n, 0);
        unordered_map<int, vector<int>> adj;
        queue<int> q; // Use queue for level-order processing (BFS)

        // Build the adjacency list and indegree array
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        // Push all leaf nodes (nodes with indegree == 1)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        // Reduce the graph layer by layer (like peeling an onion)
        int remainingNodes = n;
        while (remainingNodes > 2) {
            int layerSize = q.size();
            remainingNodes -= layerSize; // Reduce count of remaining nodes

            for (int i = 0; i < layerSize; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Remaining nodes are the centroids of the tree
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
