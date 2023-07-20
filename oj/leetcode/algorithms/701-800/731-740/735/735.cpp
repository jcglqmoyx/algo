#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> st;
        for (int x: asteroids) {
            bool alive = true;
            while (alive && x < 0 && !st.empty() && st.back() > 0) {
                alive = st.back() < -x;
                if (st.back() <= -x) st.pop_back();
            }
            if (alive) st.push_back(x);
        }
        return st;
    }
};