#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        int st = 0;
        for (int i = 1, cur = 0; i <= n; i++) {
            int t = 1;
            for (int j = i + 1; j <= n; j++) t *= (n - j + 1);
            int cnt = 0, d = 0;
            for (int j = 1; j <= n; j++) {
                if ((st | (1 << j)) == st) continue;
                cnt++;
                if (cur + cnt * t >= k) {
                    d = j;
                    break;
                }
            }
            st |= 1 << d;
            res += to_string(d);
            cur += (cnt - 1) * t;
        }
        return res;
    }
};