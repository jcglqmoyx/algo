#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * DFS
     * time: O(k ^ n), where n is the length of cookies
     */
    int distributeCookies(vector<int> &cookies, int k) {
        int res = 1e9, g[k];
        memset(g, 0, sizeof g);
        function<void(int)> dfs = [&](int u) {
            if (u == cookies.size()) {
                int t = 0;
                for (int x: g) t = max(t, x);
                res = min(res, t);
                return;
            }
            for (int i = 0; i < k; i++) {
                if (g[i] + cookies[u] <= res) {
                    g[i] += cookies[u];
                    dfs(u + 1);
                    g[i] -= cookies[u];
                }
            }
        };
        dfs(0);
        return res;
    }
};