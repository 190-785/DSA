/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, vector<string>& res, string path) {
        if (!node)
            return;
        path += to_string(node->val);
        if (!node->left && !node->right) {
            res.push_back(path);
            return;
        }
        dfs(node->left, res, path + "->");
        dfs(node->right, res, path + "->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root)
            dfs(root, res, "");
        return res;
    }
};
