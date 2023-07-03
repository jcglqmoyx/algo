#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = (int) s.size();
        if (n != goal.size()) return false;
        int last = -1;
        bool contains_duplicate = false;
        int mask = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != goal[i]) {
                cnt++;
                if (last != -1) {
                    swap(s[last], s[i]);
                    return s == goal;
                }
                last = i;
            } else {
                if (mask >> (s[i] - 'a') & 1) contains_duplicate = true;
                mask |= 1 << (s[i] - 'a');
            }
        }
        return contains_duplicate && cnt == 0 || cnt == 2;
    }
};