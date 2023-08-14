#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        for (int i = 1; i < directions.size(); i++) {
            char d = directions[i];
            if (d == 'L') {
                if (directions[i - 1] == 'R') {
                    res += 2;
                    int j = i - 2;
                    while (j >= 0 && directions[j] == 'R') res++, j--;
                    directions[i] = 'S';
                } else if (directions[i - 1] == 'S') {
                    res++;
                    directions[i] = 'S';
                }
            } else if (d == 'S') {
                int j = i - 1;
                while (j >= 0 && directions[j] == 'R') res++, j--;
            }
        }
        return res;
    }
};