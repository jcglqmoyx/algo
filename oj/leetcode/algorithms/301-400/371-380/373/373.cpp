#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = (int) nums1.size(), m = (int) nums2.size();
        struct T {
            int sum;
            int i, j;

            bool operator<(const T &t) const {
                return sum > t.sum;
            }
        };
        priority_queue<T> q;
        for (int i = 0; i < n; i++) {
            q.push({nums1[i] + nums2[0], i, 0});
        }
        vector<vector<int>> res;
        while (!q.empty() && res.size() < k) {
            auto t = q.top();
            q.pop();
            res.push_back({nums1[t.i], nums2[t.j]});
            if (t.j + 1 < m) q.push({nums1[t.i] + nums2[t.j + 1], t.i, t.j + 1});
        }
        return res;
    }
};