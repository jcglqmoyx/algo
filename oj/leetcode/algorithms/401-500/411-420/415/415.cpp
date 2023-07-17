#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = (int) num1.size() - 1, j = (int) num2.size() - 1;
        string res;
        int sum, carry = 0;
        while (i >= 0 && j >= 0) {
            sum = num1[i] + num2[j] - '0' * 2 + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
            i--, j--;
        }
        while (i >= 0) {
            sum = num1[i] - '0' + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
            i--;
        }
        while (j >= 0) {
            sum = num2[j] - '0' + carry;
            res += to_string(sum % 10);
            carry = sum / 10;
            j--;
        }
        if (carry) res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};