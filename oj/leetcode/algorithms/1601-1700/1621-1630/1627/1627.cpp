#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries) {
        int p[n + 1];
        iota(p, p + n + 1, 0);
        function<int(int)> find = [&](int x) -> int {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        };

        for (int i = threshold + 1; i <= n / 2; i++) {
            for (int j = i * 2; j <= n; j += i) {
                int pi = find(i), pj = find(j);
                if (pi != pj) p[pi] = pj;
            }
        }
        int m = (int) queries.size();
        vector<bool> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = find(queries[i][0]) == find(queries[i][1]);
        }
        return res;
    }
};