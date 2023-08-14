#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0, ten = 0, twenty = 0;
        for (int x: bills) {
            if (x == 5) five++;
            else if (x == 10) {
                if (five) five--, ten++;
                else return false;
            } else {
                if (ten && five) ten--, five--, twenty++;
                else if (five >= 3) five -= 3, twenty++;
                else return false;
            }
        }
        return true;
    }
};