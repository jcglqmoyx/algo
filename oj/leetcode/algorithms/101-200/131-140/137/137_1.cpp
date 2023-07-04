#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int cnt[32]{};
        for (int x: nums) {
            for (int i = 0; i < 32; i++) {
                if (x >> i & 1) cnt[i]++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (cnt[i] % 3) res |= 1 << i;
        }
        return res;
    }
};