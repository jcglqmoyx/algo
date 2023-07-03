#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int> &nums) {
        int res = 0, n = (int) nums.size();
        int r[n], pr[n + 1];
        fill(r, r + n, n), fill(pr, pr + n + 1, n);
        for (int i = n - 1; ~i; i--) {
            int x = nums[i];
            r[i] = min(pr[x], pr[x - 1]);
            pr[x] = i;
        }
        int pl[n + 1];
        fill(pl, pl + n + 1, -1);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            res += (r[i] - i) * (i - pl[x - 1]);
            pl[x] = i;
        }
        return res - n * (n + 1) / 2;
    }
};