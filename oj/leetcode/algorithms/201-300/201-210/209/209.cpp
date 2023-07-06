#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int INF = 1e9, res = INF;
        for (int s = 0, l = 0, r = 0; r < nums.size(); r++) {
            s += nums[r];
            while (s >= target) {
                res = min(res, r - l + 1);
                s -= nums[l];
                l++;
            }
        }
        return res == INF ? 0 : res;
    }
};