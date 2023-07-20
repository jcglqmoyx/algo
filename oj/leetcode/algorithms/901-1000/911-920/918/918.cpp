#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = (int) nums.size();
        int res = -1e9, tot = 0;
        for (int s = 0, i = 0; i < n; i++) {
            if (s < 0) s = nums[i];
            else s += nums[i];
            res = max(res, s);

            tot += nums[i];
        }
        for (int s = 0, mx = -1e9, i = 0; i < n; i++) {
            tot -= nums[i];
            s += nums[i];
            mx = max(mx, s);

            res = max(res, mx + tot);
        }
        return res;
    }
};