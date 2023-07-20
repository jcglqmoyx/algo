#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        int N = 30010;

        unordered_set<int> obs;
        for (auto &o: obstacles) {
            obs.insert(o[0] * N + o[1]);
        }
        int dx[] = {0, -1, 0, 1};
        int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        int res = 0;
        for (int c: commands) {
            if (c == -2) d = (d + 1) % 4;
            else if (c == -1) d = (d + 3) % 4;
            else {
                for (int k = 1; k <= c; k++) {
                    int a = x + dx[d], b = y + dy[d];
                    if (obs.count(a * N + b)) continue;
                    x = a, y = b;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};