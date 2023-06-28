#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumIncompatibility(vector<int> &nums, int k) {
        const int INF = 0x3f3f3f3f;
        int n = (int) nums.size(), sz = n / k;
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        for (int x: nums) cnt[x]++;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > k) return -1;
        }
        int incompatibility[1 << n];
        memset(incompatibility, 0x3f, sizeof incompatibility);
        int bit_count[1 << n];
        for (int i = 0; i < 1 << n; i++) {
            bit_count[i] = __builtin_popcount(i);
            if (bit_count[i] == sz) {
                int exits = 0;
                bool ok = true;
                int mn = n + 1, mx = 0;
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        if (exits >> nums[j] & 1) {
                            ok = false;
                            break;
                        }
                        exits |= 1 << nums[j];
                        mn = min(mn, nums[j]);
                        mx = max(mx, nums[j]);
                    }
                }
                if (ok) incompatibility[i] = mx - mn;
            }
        }
        int f[1 << n];
        memset(f, 0x3f, sizeof f);
        for (int i = 1; i < 1 << n; i++) {
            if (bit_count[i] % sz == 0) {
                if (bit_count[i] == sz) f[i] = incompatibility[i];
                else {
                    for (int sub = i; sub; sub = (sub - 1) & i) {
                        if (bit_count[sub] % sz == 0) {
                            f[i] = min(f[i], f[i ^ sub] + incompatibility[sub]);
                        }
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};