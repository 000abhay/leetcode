class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0); // Count outgoing edges
        vector<vector<int>> reverseGraph(n); // Reverse graph
        queue<int> q;
        vector<int> result;

        // Build reverse graph and calculate outdegree
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) {
                q.push(i); // Terminal nodes are safe
            }
        }

        // Process nodes with zero outdegree
        while (!q.empty()) {
            int node = q.front();
           // cout<<node<<endl;
            q.pop();
            result.push_back(node);
            for (int neighbor : reverseGraph[node]) {
                outdegree[neighbor]--;
                if (outdegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(result.begin(), result.end()); // Sort result
        return result;
    }
};
