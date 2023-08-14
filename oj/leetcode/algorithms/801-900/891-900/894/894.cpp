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
public:
    vector<TreeNode *> allPossibleFBT(int n) {
        function<vector<TreeNode *>(int)> dfs = [&](int u) -> vector<TreeNode *> {
            if (u == 1) return {new TreeNode{0}};
            vector<TreeNode *> res;
            for (int i = 1; i < u; i += 2) {
                auto left_set = dfs(i), right_set = dfs(u - 1 - i);
                for (auto l: left_set) {
                    for (auto r: right_set) {
                        auto root = new TreeNode(0);
                        root->left = l, root->right = r;
                        res.push_back(root);
                    }
                }
            }
            return res;
        };
        return dfs(n);
    }
};