#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for (char c: jewels) s.insert(c);
        int res = 0;
        for (char c: stones) {
            if (s.count(c)) res++;
        }
        return res;
    }
};