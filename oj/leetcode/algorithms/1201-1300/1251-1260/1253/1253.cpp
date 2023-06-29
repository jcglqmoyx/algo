#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum) {
        int m = (int) colsum.size();
        vector<int> col_sum = colsum;
        vector<vector<int>> res(2, vector<int>(m));
        for (int j = 0; j < m && upper; j++) {
            if (colsum[j] == 2) res[0][j] = res[1][j] = 1, colsum[j] = 0, upper--, lower--;
        }
        for (int j = 0; j < m && upper; j++) {
            if (colsum[j]) colsum[j] = 0, res[0][j] = 1, upper--;
        }
        for (int j = 0; j < m && lower; j++) {
            if (colsum[j]) colsum[j] = 0, res[1][j] = 1, lower--;
        }
        if (upper || lower) return {};
        for (int j = 0; j < m; j++) {
            if (res[0][j] + res[1][j] != col_sum[j]) return {};
        }
        return res;
    }
};