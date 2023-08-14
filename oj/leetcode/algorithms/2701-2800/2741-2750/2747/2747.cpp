#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries) {
        using PII = pair<int, int>;
        sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int m = (int) queries.size();
        vector<PII> v(m);
        for (int i = 0; i < m; i++) {
            v[i] = {queries[i], i};
        }
        sort(v.begin(), v.end(), [](PII &a, PII &b) {
            return a.first < b.first;
        });
        multiset<PII> s;
        unordered_map<int, int> map;
        vector<int> res(m);
        for (int i = 0, j = 0; i < m; i++) {
            int end = v[i].first, start = end - x, idx = v[i].second;
            while (j < logs.size() && logs[j][1] <= end) {
                if (logs[j][1] >= start) s.insert({logs[j][1], logs[j][0]}), map[logs[j][0]]++;
                j++;
            }
            while (!s.empty() && s.begin()->first < start) {
                auto t = s.begin();
                map[t->second]--;
                if (map[t->second] == 0) map.erase(t->second);
                s.erase(t);
            }
            res[idx] = n - (int) map.size();
        }
        return res;
    }
};