#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int halveArray(vector<int> &nums) {
        priority_queue<double> heap;
        double sum = 0;
        for (double x: nums) heap.emplace(x), sum += x;
        int res = 0;
        double reduce = 0;
        while (true) {
            double t = heap.top() / 2;
            heap.pop();
            res++;
            reduce += t;
            heap.push(t);
            if (reduce >= sum / 2) break;
        }
        return res;
    }
};