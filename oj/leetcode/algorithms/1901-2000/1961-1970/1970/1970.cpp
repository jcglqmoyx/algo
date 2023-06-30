#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int n = (int) cells.size();
        auto check = [&](int m) {
            bool st[row + 1][col + 1];
            memset(st, 0, sizeof st);
            for (int i = 0; i < m; i++) {
                st[cells[i][0]][cells[i][1]] = true;
            }
            queue<pair<int, int>> q;
            for (int j = 1; j <= col; j++) {
                if (!st[1][j]) q.emplace(1, j);
            }
            while (!q.empty()) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int a = t.first + dx[i], b = t.second + dy[i];
                    if (a < 1 || a > row || b < 1 || b > col || st[a][b]) continue;
                    if (a == row) return true;
                    st[a][b] = true;
                    q.emplace(a, b);
                }
            }
            return false;
        };
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (check(m)) l = m;
            else r = m - 1;
        }
        return l;
    }
};