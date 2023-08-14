#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int l = 1, r = (int) arr.size() - 2;
        while (l < r) {
            int m = (l + r) >> 1;
            if (arr[m] > arr[m - 1]) {
                if (arr[m] > arr[m + 1]) return m;
                else l = m + 1;
            } else r = m;
        }
        return l;
    }
};