#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
        struct Robot {
            int p, h;
            char d;
            int idx;
        };
        int n = (int) positions.size();
        vector<Robot> v(n);
        for (int i = 0; i < positions.size(); i++) {
            v[i] = {positions[i], healths[i], directions[i], i};
        }
        sort(v.begin(), v.end(), [](Robot &a, Robot &b) {
            return a.p < b.p;
        });
        vector<Robot> tmp = {v[0]};
        for (int i = 1; i < n; i++) {
            bool add = true;
            if (v[i].d == 'L' && !tmp.empty() && tmp.back().d == 'R') {
                while (!tmp.empty() && tmp.back().d == 'R') {
                    if (tmp.back().h > v[i].h) {
                        tmp.back().h--;
                        add = false;
                        break;
                    } else if (tmp.back().h < v[i].h) {
                        tmp.pop_back();
                        v[i].h--;
                    } else {
                        tmp.pop_back();
                        add = false;
                        break;
                    }
                }
                if (add) tmp.push_back(v[i]);
            } else {
                tmp.push_back(v[i]);
            }
        }
        sort(tmp.begin(), tmp.end(), [](Robot &a, Robot &b) {
            return a.idx < b.idx;
        });
        vector<int> res;
        res.reserve(tmp.size());
        for (auto &robot: tmp) {
            res.push_back(robot.h);
        }
        return res;
    }
};