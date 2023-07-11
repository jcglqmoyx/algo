#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const int N = 510, M = N << 1;

int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs1(TreeNode *node) {
    int v = node->val;
    if (node->left) {
        int l = node->left->val;
        add(v, l), add(l, v);
        dfs1(node->left);
    }
    if (node->right) {
        int r = node->right->val;
        add(v, r), add(r, v);
        dfs1(node->right);
    }
}

void dfs2(vector<int> &res, int cur, int k, int dist) {
    st[cur] = true;
    if (dist == k) res.push_back(cur);
    else if (dist > k) return;
    for (int i = h[cur]; i != -1; i = ne[i]) {
        if (!st[e[i]]) dfs2(res, e[i], k, dist + 1);
    }
}

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        memset(h, -1, sizeof h), idx = 0;
        memset(st, 0, sizeof st);
        dfs1(root);
        vector<int> res;
        dfs2(res, target->val, k, 0);
        return res;
    }
};