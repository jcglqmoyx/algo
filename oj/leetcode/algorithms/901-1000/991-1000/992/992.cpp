#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        function<int(int)> get = [&](int unique) -> int {
            int res = 0;
            unordered_map<int, int> cnt;
            for (int l = 0, r = 0; r < nums.size(); r++) {
                cnt[nums[r]]++;
                while (cnt.size() > unique) {
                    cnt[nums[l]]--;
                    if (cnt[nums[l]] == 0) cnt.erase(nums[l]);
                    l++;
                }
                res += l;
            }
            return res;
        };
        return get(k - 1) - get(k);
    }
};