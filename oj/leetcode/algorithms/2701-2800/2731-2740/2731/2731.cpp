#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumDistance(vector<int> &nums, string s, int d) {
        using LL = long long;
        const int MOD = 1e9 + 7;
        int n = (int) nums.size();
        vector<LL> v(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') v[i] = (LL) nums[i] - d;
            else v[i] = (LL) nums[i] + d;
        }
        sort(v.begin(), v.end());
        LL tot = 0;
        for (int i = 1; i < n; i++) {
            tot += v[i] - v[0];
        }
        LL res = tot;
        for (int i = 1; i < n - 1; i++) {
            tot -= (v[i] - v[i - 1]) * (n - i);
            res = (res + tot) % MOD;
        }
        return (int) res;
    }
};