#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int> &nums) {
        using ll = long long;
        ll res = 0, p = 0, n = 0;
        for (int x: nums) {
            ll pp = p, nn = n;
            pp = max(p, n + x);
            nn = max(n, p - x);
            res = max(res, pp);
            p = pp, n = nn;
        }
        return res;
    }
};