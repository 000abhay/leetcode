class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq1;  // Frequency map for nums1
    unordered_map<int, int> freq2;  // Frequency map for nums2

    FindSumPairs(vector<int>& nums1_, vector<int>& nums2_) {
        nums1 = nums1_;
        nums2 = nums2_;
        for (int num : nums1)
            freq1[num]++;
        for (int num : nums2)
            freq2[num]++;
    }
    
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int c = 0;
        for (auto [num, count2] : freq2) {
            int complement = tot - num;
            if (freq1.count(complement)) {
                c += freq1[complement] * count2;
            }
        }
        return c;
    }
};
