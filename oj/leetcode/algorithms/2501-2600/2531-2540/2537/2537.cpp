#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countGood(vector<int> &nums, int k) {
        long long res = 0;
        unordered_map<int, int> cnt;
        for (int l = 0, r = 0, pairs = 0; r < nums.size(); r++) {
            pairs += cnt[nums[r]];
            cnt[nums[r]]++;
            while (pairs >= k) {
                pairs -= cnt[nums[l]] - 1;
                cnt[nums[l]]--;
                l++;
            }
            res += l;
        }
        return res;
    }
};