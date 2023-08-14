#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        double f[n][n];
        memset(f, 0, sizeof f);
        f[row][column] = 1.0;
        while (k--) {
            double g[n][n];
            memset(g, 0, sizeof g);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int d = 0; d < 8; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if (x < 0 || x >= n || y < 0 || y >= n) continue;
                        g[x][y] += f[i][j] / 8;
                    }
                }
            }
            memcpy(f, g, sizeof g);
        }
        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res += f[i][j];
            }
        }
        return res;
    }
};