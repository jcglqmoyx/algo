#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k) {
        deque<int> q;
        int res = -1e9;
        for (int j = 0; j < points.size(); j++) {
            int xj = points[j][0], yj = points[j][1];
            while (!q.empty()) {
                int xi = points[q.front()][0];
                if (xj - xi > k) q.pop_front();
                else break;
            }
            if (!q.empty()) {
                int xi = points[q.front()][0], yi = points[q.front()][1];
                res = max(res, xj + yj - (xi - yi));
            }
            while (!q.empty()) {
                int xi = points[q.back()][0], yi = points[q.back()][1];
                if (xj - yj <= xi - yi) q.pop_back();
                else break;
            }
            q.push_back(j);
        }
        return res;
    }
};