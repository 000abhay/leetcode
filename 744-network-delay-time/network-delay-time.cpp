class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Min-heap priority queue to store {cost, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k}); // Start with node k and cost 0

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            // Explore all neighbors
            for (auto& [neighbor, weight] : adj[node]) {
                int new_cost = cost + weight;
                if (new_cost < dist[neighbor]) {
                    dist[neighbor] = new_cost;
                    pq.push({new_cost, neighbor});
                }
            }
        }

        // Find the maximum time among all reachable nodes
        int max_time = *max_element(dist.begin() + 1, dist.end());
        return (max_time == INT_MAX) ? -1 : max_time;
    }
};