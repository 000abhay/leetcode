#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
     if (s.size() < t.size()) return "";

    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;  // build frequency map

    int have = 0, needCount = need.size();
    int left = 0, minLen = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        // only increase 'have' when freq matches
        if (need.count(c) && window[c] == need[c])
            have++;

        // when window is valid, try to shrink from left
        while (have == needCount) {
            if ((right - left + 1) < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // shrink the window
            char leftChar = s[left];
            window[leftChar]--;
            if (need.count(leftChar) && window[leftChar] < need[leftChar])
                have--;
            left++;
        }
    }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
