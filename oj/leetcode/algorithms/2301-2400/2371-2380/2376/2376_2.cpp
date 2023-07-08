#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSpecialNumbers(int n) {
        int m = n;
        vector<int> digits;
        while (m) digits.push_back(m % 10), m /= 10;
        reverse(digits.begin(), digits.end());
        m = (int) digits.size();
        int f[m][10][1 << 10];
        memset(f, -1, sizeof f);
        function<int(int, int, int, bool)> dp = [&](int u, int d, int mask, bool limit) -> int {
            if (u == m) return 1;
            if (!limit && f[u][d][mask] != -1) return f[u][d][mask];
            int res = 0, mx = limit ? digits[u] : 9;
            for (int i = u == 0 ? 1 : 0; i <= mx; i++) {
                if ((mask | (1 << i)) == mask) continue;
                res += dp(u + 1, i, mask | (1 << i), limit && i == mx);
            }
            if (!limit) f[u][d][mask] = res;
            return res;
        };
        int res = dp(0, 0, 0, true);
        for (int i = 1; i < m; i++) {
            int t = 9;
            for (int j = 1, op = 9; j < i; j++, op--) {
                t *= op;
            }
            res += t;
        }
        return res;
    }
};