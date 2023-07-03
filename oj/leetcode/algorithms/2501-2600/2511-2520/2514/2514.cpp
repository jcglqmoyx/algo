#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MOD = 1e9 + 7;
const int N = 100010;

LL p[N], f[N];

LL quick_power(LL a, int b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int init = []() {
    p[0] = f[0] = 1;
    for (int i = 1; i < N; i++) {
        p[i] = p[i - 1] * i % MOD;
        f[i] = quick_power(p[i], MOD - 2);
    }
    return 0;
}();

class Solution {
public:
    int countAnagrams(string s) {
        int n = (int) s.size();
        LL res = 1;
        for (int i = 0; i < n; i++) {
            int cnt[26]{};
            int j = i;
            while (j < n && s[j] != ' ') {
                cnt[s[j] - 'a']++;
                j++;
            }
            LL t = p[j - i];
            i = j;
            for (int k: cnt) {
                if (k > 1) {
                    t = t * f[k] % MOD;
                }
            }
            res = (res * t) % MOD;
        }
        return (int) res;
    }
};