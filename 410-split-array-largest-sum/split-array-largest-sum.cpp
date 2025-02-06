class Solution {
public:
    bool fun(vector<int>& nums, int n, int m, int k) {
        int sum = 0, count = 1;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > m) { // If current sum exceeds mid (m)
                sum = nums[i]; // Start a new subarray
                count++; // Increase partition count
                
                if (count > k) return false; // More partitions than allowed
            } else {
                sum += nums[i];
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int mi = *max_element(nums.begin(), nums.end());
        int mx = accumulate(nums.begin(), nums.end(), 0);

        while (mi < mx) {
            int mid = mi + (mx - mi) / 2;
            if (fun(nums, n, mid, k)) {
                mx = mid; // Try reducing maximum sum
            } else {
                mi = mid + 1; // Increase minimum sum
            }
        }
        return mi; // mi represents the minimum largest sum possible
    }
};
