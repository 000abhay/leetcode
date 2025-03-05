class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
         vector<vector<int>> ans;
        int i = 0, j = 0;
        int r1 = nums1.size(), r2 = nums2.size();

        // Merge both arrays in sorted order
        while (i < r1 && j < r2) {
            if (nums1[i][0] < nums2[j][0]) {
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            } else if (nums1[i][0] > nums2[j][0]) {
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            } else {  // If IDs are the same, sum their values
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
        }

        // Add remaining elements from nums1
        while (i < r1) {
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        // Add remaining elements from nums2
        while (j < r2) {
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return ans;
    }
};