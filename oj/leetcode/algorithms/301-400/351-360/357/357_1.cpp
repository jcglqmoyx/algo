class Solution {
    static int get(int n) {
        int res = 9;
        for (int i = 1, u = 9; i < n; i++, u--) {
            res *= u;
        }
        return res;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        else if (n == 1) return 10;
        int res = 10;
        for (int i = 2; i <= n; i++) {
            res += get(i);
        }
        return res;
    }
};