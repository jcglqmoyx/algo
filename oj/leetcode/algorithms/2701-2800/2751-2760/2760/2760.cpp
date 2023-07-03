#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        int n = (int) nums.size(), res = 0;
        for (int i = 0; i < n && n - i > res; i++) {
            if (nums[i] <= threshold && !(nums[i] & 1)) {
                int j = i + 1;
                while (j < n) {
                    if (nums[j] <= threshold && (nums[j] & 1) != (nums[j - 1] & 1)) j++;
                    else break;
                }
                res = max(res, j - i);
                i = j - 1;
            }
        }
        return res;
    }
};