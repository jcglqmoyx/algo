#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        int f[m];
        for (int j = 0; j < m; j++) f[j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            int g[m];
            memcpy(g, f, sizeof f);
            for (int j = 0; j < m; j++) {
                f[j] = g[j] + matrix[i][j];
                if (j) f[j] = min(f[j], g[j - 1] + matrix[i][j]);
                if (j < m - 1) f[j] = min(f[j], g[j + 1] + matrix[i][j]);
            }
        }
        return *min_element(f, f + m);
    }
};