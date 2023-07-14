#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int f[40001];
        memset(f, 0, sizeof f);
        int res = 0, offset = 20000;
        for (int x: arr) {
            int y = x - difference + offset;
            x += offset;
            f[x] = max(f[x], f[y] + 1);
            res = max(res, f[x]);
        }
        return res;
    }
};