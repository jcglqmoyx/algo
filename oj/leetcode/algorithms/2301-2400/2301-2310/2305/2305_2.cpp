#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * state-compression dp
     * time O(k⋅3^n), where n is the length of cookies
     */
    int distributeCookies(vector<int> &cookies, int k) {
        int n = (int) cookies.size();
        int f[1 << n], s[1 << n];
        memset(f, 0x3f, sizeof f);
        for (int i = 1; i < 1 << n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    sum += cookies[j];
                }
            }
            f[i] = s[i] = sum;
        }
        for (int i = 1; i < k; i++) {
            for (int j = (1 << n) - 1; j; j--) {
                for (int sub = j; sub; sub = (sub - 1) & j) {
                    f[j] = min(f[j], max(f[j - sub], s[sub]));
                }
            }
        }
        return f[(1 << n) - 1];
    }
};