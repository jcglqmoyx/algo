#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumLines(vector<vector<int>> &p) {
        using LL = long long;
        int res = 1, n = (int) p.size();
        if (n == 1) return 0;
        sort(p.begin(), p.end());
        LL dx = p[1][0] - p[0][0], dy = p[1][1] - p[0][1];
        for (int i = 2; i < n; i++) {
            LL ndx = p[i][0] - p[i - 1][0], ndy = p[i][1] - p[i - 1][1];
            if (ndx * dy != ndy * dx) res++;
            dx = ndx, dy = ndy;
        }
        return res;
    }
};