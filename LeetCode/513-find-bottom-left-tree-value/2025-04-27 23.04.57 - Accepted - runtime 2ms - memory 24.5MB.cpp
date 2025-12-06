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
    void dfs(TreeNode* node, int depth, int& maxDepth, int& leftmostValue) {
        if (!node)
            return;
        if (depth > maxDepth) {
            maxDepth = depth;
            leftmostValue = node->val;
        }
        dfs(node->left, depth + 1, maxDepth, leftmostValue);
        dfs(node->right, depth + 1, maxDepth, leftmostValue);
    }

    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;
        int leftmostValue = root->val;
        dfs(root, 0, maxDepth, leftmostValue);
        return leftmostValue;
    }
};
