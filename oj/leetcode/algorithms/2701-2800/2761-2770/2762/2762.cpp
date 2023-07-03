#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int> &nums) {
        multiset<int> S;
        long long res = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            S.insert(nums[i]);
            while (*S.rbegin() - *S.begin() > 2) {
                S.erase(S.find(nums[j]));
                j++;
            }
            res += i - j + 1;
        }
        return res;
    }
};