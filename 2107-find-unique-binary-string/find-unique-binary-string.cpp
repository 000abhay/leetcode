class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result = "";

        for (int i = 0; i < nums.size(); i++) {

            result += (nums[i][i] == '0') ? '1' : '0'; // Flip the diagonal character

        }

        return result;
    }
};