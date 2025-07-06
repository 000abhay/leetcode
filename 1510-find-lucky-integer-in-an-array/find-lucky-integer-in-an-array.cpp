class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;

        // Check if frequency matches value
        for (auto& [num, count] : freq) {
            if (num == count) {
                result = max(result, num);
            }
        }

        return result;
    }
};
