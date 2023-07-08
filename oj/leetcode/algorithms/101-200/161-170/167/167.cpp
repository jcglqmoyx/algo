#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int l = 0, r = (int) numbers.size() - 1; l < r;) {
            if (numbers[l] + numbers[r] > target) r--;
            else if (numbers[l] + numbers[r] < target) l++;
            else return {l + 1, r + 1};
        }
        return {};
    }
};