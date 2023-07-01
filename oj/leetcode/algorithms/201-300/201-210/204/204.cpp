#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int prime[n + 1], cnt = 0;
        bool st[n + 1];
        memset(st, 0, sizeof st);
        for (int i = 2; i < n; i++) {
            if (!st[i]) prime[cnt++] = i;
            for (int j = 0; prime[j] * i < n; j++) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) break;
            }
        }
        return cnt;
    }
};