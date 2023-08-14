#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int l = 1, r = 1e7 + 1;
        while (l < r) {
            int m = (l + r) >> 1;
            double time = 0;
            for (int i = 0; i + 1 < dist.size(); i++) {
                time += (dist[i] + m - 1) / m;
            }
            time += (double) dist.back() / m;
            if (time <= hour) r = m;
            else l = m + 1;
        }
        return l == 1e7 + 1 ? -1 : l;
    }
};