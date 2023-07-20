#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 1;
        for (int l = 0, r = 1, p = 0; r < s.size(); r++) {
            if (s[r] == s[r - 1]) p++;
            while (p > 1) {
                if (s[l] == s[l + 1]) p--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};