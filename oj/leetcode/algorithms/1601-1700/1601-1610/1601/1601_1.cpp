#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * time: O(n * 2 ^ m), where m is the number of requests, n is the number of buildings
     */
    int maximumRequests(int n, vector<vector<int>> &requests) {
        int res = 0, m = (int) requests.size();
        for (int i = 1; i < 1 << m; i++) {
            int transfer = __builtin_popcount(i);
            if (transfer <= res) continue;
            int cnt[n];
            memset(cnt, 0, sizeof cnt);
            for (int j = 0; j < m; j++) {
                if (i >> j & 1) {
                    cnt[requests[j][0]]--;
                    cnt[requests[j][1]]++;
                }
            }
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (cnt[j] != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) res = transfer;
        }
        return res;
    }
};