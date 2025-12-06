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
    int HeightLeft(TreeNode* root) {
        int ht = 0;
        while (root) {
            ht++;
            root = root->left;
        }
        return ht;
    }
    int HeightRight(TreeNode* root) {
        int ht = 0;
        while (root) {
            ht++;
            root = root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int Lht = HeightLeft(root);
        int Rht = HeightRight(root);
        if (Lht == Rht)
            return (1 << Lht) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};