class Solution {
    double pow(double x, long long n) {
        double res = 1.0;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

public:
    double myPow(double x, int n) {
        long long m = n;
        return n >= 0 ? pow(x, m) : 1 / pow(x, -m);
    }
};