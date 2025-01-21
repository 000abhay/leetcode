class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        typedef long long ll;
        int n = grid[0].size();
        
        // Calculate prefix sums for both rows
        vector<ll> top(n), bottom(n);
        top[n - 1] = grid[0][n - 1];
        bottom[0] = grid[1][0];
        
        for (int i = n - 2; i >= 0; i--) {
            top[i] = top[i + 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            bottom[i] = bottom[i - 1] + grid[1][i];
        }
        
        // Calculate the minimum possible maximum score for Player 1
        ll result = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            ll score1 = i + 1 < n ? top[i + 1] : 0;  // Player 1's score if Player 2 splits here
            ll score2 = i - 1 >= 0 ? bottom[i - 1] : 0; // Player 2's score before split
            result = min(result, max(score1, score2));
        }
        
        return result;
    }
};
