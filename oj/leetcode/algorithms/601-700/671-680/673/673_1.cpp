#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = (int) nums.size(), f[n], g[n], max_len = 0, res = 0;
        for (int i = 0; i < n; i++) {
            f[i] = g[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    } else if (f[i] == f[j] + 1) {
                        g[i] += g[j];
                    }
                }
            }
            if (max_len < f[i]) {
                max_len = f[i];
                res = g[i];
            } else if (max_len == f[i]) {
                res += g[i];
            }
        }
        return res;
    }
};
