#include <bits/stdc++.h>

using namespace std;

int f[9];

int init = []() {
    f[0] = 1;
    f[1] = 10;
    f[2] = 91;
    f[3] = 739;
    f[4] = 5275;
    f[5] = 32491;
    f[6] = 168571;
    f[7] = 712891;
    f[8] = 2345851;
    return 0;
}();

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        return f[n];
    }
};