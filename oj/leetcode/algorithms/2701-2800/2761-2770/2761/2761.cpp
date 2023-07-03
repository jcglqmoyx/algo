#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int primes[N], cnt = 0;
bool vis[N];

int init = []() {
    memset(vis, 0, sizeof vis);
    for (int i = 2; i < N; i++) {
        if (!vis[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] * i < N; j++) {
            vis[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
    return 0;
}();

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if (n & 1) {
            if (n > 4 && !vis[n - 2]) return {{2, n - 2}};
            return {};
        }
        vector<vector<int>> ans;
        for (int i = 0; i < cnt && primes[i] * 2 <= n; i++) {
            if (!vis[n - primes[i]]) {
                ans.push_back({primes[i], n - primes[i]});
            }
        }
        return ans;
    }
};