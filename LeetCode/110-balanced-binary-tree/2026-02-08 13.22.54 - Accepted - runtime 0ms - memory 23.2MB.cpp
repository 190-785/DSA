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
    int checkHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int Lh = checkHeight(root->left);
        int Rh = checkHeight(root->right);
        if (Lh == -1 || Rh == -1)
            return -1;
        if (abs(Lh - Rh) > 1)
            return -1;
        return max(Lh, Rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int res = checkHeight(root);
        if (res == -1)
            return false;
        return true;
    }
};