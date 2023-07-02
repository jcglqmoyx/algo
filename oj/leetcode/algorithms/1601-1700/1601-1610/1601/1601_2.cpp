#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * time: O(2 ^ m), where m is the number of requests
     */
    int maximumRequests(int n, vector<vector<int>> &requests) {
        int init = 0, m = (int) requests.size();
        for (int i = 0; i < m; ++i) {
            int from = requests[i][0], to = requests[i][1];
            if (from == to) {
                init++;
                requests[i] = requests.back();
                requests.pop_back();
                i--, m--;
            }
        }
        int res = 0;
        int cnt[n];
        memset(cnt, 0, sizeof cnt);
        function<void(int, int, int)> dfs = [&](int u, int count_chosen, int count_failure) {
            if (u == m) {
                if (!count_failure) res = max(res, count_chosen);
                return;
            }
            dfs(u + 1, count_chosen, count_failure);

            int from = requests[u][0], to = requests[u][1];
            cnt[from]--, cnt[to]++;
            if (!cnt[from]) count_failure--;
            else if (cnt[from] == -1) count_failure++;
            if (!cnt[to]) count_failure--;
            else if (cnt[to] == 1) count_failure++;
            dfs(u + 1, count_chosen + 1, count_failure);
            cnt[from]++, cnt[to]--;

        };
        dfs(0, 0, 0);
        return res + init;
    }
};