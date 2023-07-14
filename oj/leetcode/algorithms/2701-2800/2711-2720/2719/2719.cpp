#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    int get(const string &s, int min_sum, int max_sum) {
        int n = (int) s.size();
        int f[n][max_sum + 1];
        memset(f, -1, sizeof f);
        function<int(int, int, bool)> dp = [&](int u, int sum, bool limited) -> int {
            if (sum > max_sum) return 0;
            if (u == n) {
                if (sum < min_sum) return 0;
                return 1;
            }
            if (!limited && f[u][sum] != -1) return f[u][sum];
            int res = 0;
            int mx = limited ? s[u] - '0' : 9;
            for (int i = 0; i <= mx; i++) {
                res += dp(u + 1, sum + i, limited && i == mx);
                res %= MOD;
            }
            if (!limited) f[u][sum] = res;
            return res;
        };
        return dp(0, 0, true);
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int res = get(num2, min_sum, max_sum) - get(num1, min_sum, max_sum);
        int digit_sum = 0;
        for (char c: num1) {
            digit_sum += c - '0';
        }
        if (digit_sum >= min_sum && digit_sum <= max_sum) res++;
        res = (res + MOD) % MOD;
        return res;
    }
};