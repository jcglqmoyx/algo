#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0;
        int l = 0, r = (int) height.size() - 1;
        int lm = 0, rm = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                res += max(0, lm - height[l]);
                lm = max(lm, height[l]);
                l++;
            } else {
                res += max(0, rm - height[r]);
                rm = max(rm, height[r]);
                r--;
            }
        }
        return res;
    }
};