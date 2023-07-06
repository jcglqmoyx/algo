#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long makeSubKSumEqual(vector<int> &arr, int k) {
        int n = (int) arr.size();
        bool st[n];
        memset(st, 0, sizeof st);
        long long res = 0;
        for (int i = 0; i < k; i++) {
            vector<int> t;
            for (int j = i; !st[j]; j = (j + k) % n) {
                t.push_back(arr[j]);
                st[j] = true;
            }
            sort(t.begin(), t.end());
            int m = (int) t.size();
            for (int j = 0; j < m; j++) {
                res += abs(t[j] - t[m / 2]);
            }
        }
        return res;
    }
};