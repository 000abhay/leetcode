#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool knapsack(vector<int>& nums, int n, int w) {
        vector<vector<bool>> adj(n + 1, vector<bool>(w + 1, false));

        // Base cases
        for (int i = 0; i <= n; i++) {
            adj[i][0] = true;  // Sum 0 is always possible
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (nums[i - 1] <= j) {
                    adj[i][j] = adj[i - 1][j] || adj[i - 1][j - nums[i - 1]];
                } else {
                    adj[i][j] = adj[i - 1][j];
                }
            }
        }
        
        return adj[n][w];
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum % 2 != 0) {
            return false;
        }
        
        return knapsack(nums, n, sum / 2);
    }
};
