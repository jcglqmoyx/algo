#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int f[10];
        f[0] = 1;
        for (int i = 1; i < 10; i++) f[i] = f[i - 1] * i;
        string res;
        int st = 0;
        for (int i = 1, cur = 0; i <= n; i++) {
            int t = f[n - i];
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