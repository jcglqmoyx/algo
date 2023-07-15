#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        using LL = long long;
        vector<vector<int>> res;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n - 3; a++) {
            if ((LL) nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break;
            if (a > 0 && nums[a - 1] == nums[a]) continue;
            if ((LL) nums[a] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            for (int b = a + 1; b < n - 2; b++) {
                if ((LL) nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) break;
                if (b > a + 1 && nums[b - 1] == nums[b]) continue;
                if ((LL) nums[a] + nums[b] + nums[n - 2] + nums[n - 1] < target) continue;
                int c = b + 1, d = n - 1;
                while (c < d) {
                    LL sum = (LL) nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c] == nums[c + 1]) c++;
                        c++;
                        while (c < d && nums[d] == nums[d - 1]) d--;
                        d--;
                    } else if (sum < target) {
                        c++;
                    } else {
                        d--;
                    }
                }
            }
        }
        return res;
    }
};