#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = N << 2;

int h[N], e[M], ne[M], idx;
int memo[N]; // 0: not a safe node, 1: is a safe node, -1: not processed yet, 2: processing

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u) {
    if (memo[u] == 0 || memo[u] == 1) return memo[u];
    if (memo[u] == 2) {
        memo[u] = 0;
        return false;
    }
    if (h[u] == -1) {
        memo[u] = 1;
        return true;
    }
    memo[u] = 2;
    bool flag = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!dfs(j)) {
            flag = false;
            break;
        }
    }
    if (flag) {
        memo[u] = 1;
        return true;
    } else {
        memo[u] = 0;
        return false;
    }
}

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = (int) graph.size();
        memset(h, -1, sizeof(int) * n), idx = 0;
        memset(memo, -1, sizeof memo);
        for (int from = 0; from < n; from++) {
            for (int to: graph[from]) {
                add(from, to);
            }
        }
        vector<int> res;
        for (int from = 0; from < n; from++) {
            if (dfs(from)) res.push_back(from);
        }
        return res;
    }
};
