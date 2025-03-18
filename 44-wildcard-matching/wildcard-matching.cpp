class Solution {
public:
    vector<vector<int>> arr;

    bool fun(string &s, string &p, int i, int j) {
        if (j == p.length()) return i == s.length(); // If pattern is over, check if s is also over
        if (i > s.length()) return false; // Prevent out-of-bounds
        
        if (arr[i][j] != -1) return arr[i][j]; // Memoization
        
        bool match = false;
        if (i < s.length() && (s[i] == p[j] || p[j] == '?')) {
            match = fun(s, p, i + 1, j + 1);
        } else if (p[j] == '*') {
            // '*' can match 0 or more characters
            match = fun(s, p, i, j + 1) || (i < s.length() && fun(s, p, i + 1, j));
        }
        return arr[i][j] = match;
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        arr.assign(n + 1, vector<int>(m + 1, -1)); // Initialize memoization table
        return fun(s, p, 0, 0);
    }
};
