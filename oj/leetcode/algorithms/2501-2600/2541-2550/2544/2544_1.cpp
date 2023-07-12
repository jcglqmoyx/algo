class Solution {
public:
    int alternateDigitSum(int n) {
        int d[10], cnt = 0;
        while (n) {
            d[cnt++] = n % 10;
            n /= 10;
        }
        int res = 0;
        for (int i = cnt - 1, t = 1; i >= 0; i--, t *= -1) {
            res += d[i] * t;
        }
        return res;
    }
};