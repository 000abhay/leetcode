#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        // 1. Build frequency table for t
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = t.size();          // total chars still needed
        int left = 0, start = 0;
        int minLen = INT_MAX;

        // 2. Expand the right edge of the window
        for (int right = 0; right < (int)s.size(); ++right) {
            char ch = s[right];
            if (need.count(ch) && --need[ch] >= 0)  // quota met?
                --required;

            // 3. Shrink from the left while the window is valid
            while (required == 0) {
                // Record best window so far
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Pop s[left] out of the window
                char leftChar = s[left++];
                if (need.count(leftChar) && ++need[leftChar] > 0)
                    ++required;          // we now need this char again
            }
        }
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
