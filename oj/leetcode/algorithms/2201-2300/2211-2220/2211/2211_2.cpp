#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCollisions(string &s) {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](auto c) { return c != 'L'; }));
        s.erase(find_if(s.rbegin(), s.rend(), [](auto c) { return c != 'R'; }).base(), s.end());
        return (int) (s.length() - count(s.begin(), s.end(), 'S'));
    }
};