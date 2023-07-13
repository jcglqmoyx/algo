#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        int d[numCourses];
        memset(d, 0, sizeof d);
        vector<vector<int>> g(numCourses);
        for (auto &p: prerequisites) {
            g[p[0]].push_back(p[1]);
            d[p[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!d[i]) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int x: g[t]) {
                if (--d[x] == 0) {
                    q.push(x);
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (d[i]) return false;
        }
        return true;
    }
};