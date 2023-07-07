#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = (int) answerKey.size(), res = 0;
        int st[n + 1], sf[n + 1];
        st[0] = sf[0] = 0;
        for (int i = 1; i <= n; i++) {
            st[i] = st[i - 1] + (answerKey[i - 1] == 'T');
            sf[i] = sf[i - 1] + (answerKey[i - 1] == 'F');
        }
        for (int l = 1, r = 1; r <= n; r++) {
            while (st[r] - st[l - 1] + k < r - l + 1) l++;
            res = max(res, r - l + 1);
        }
        for (int l = 1, r = 1; r <= n; r++) {
            while (sf[r] - sf[l - 1] + k < r - l + 1) l++;
            res = max(res, r - l + 1);
        }
        return res;
    }
};