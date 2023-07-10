#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int res = 1e9;

    int dfs(TreeNode *node, int depth) {
        if (!node) return 0;
        if (!node->left && !node->right) res = min(res, depth);
        int l = dfs(node->left, depth + 1);
        int r = dfs(node->right, depth + 1);
        return min(l, r);
    }

public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        dfs(root, 1);
        return res;
    }
};