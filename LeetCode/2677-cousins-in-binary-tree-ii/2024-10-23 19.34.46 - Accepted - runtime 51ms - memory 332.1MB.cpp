/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x, left, right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        root->val = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int totalSum = 0;
            vector<TreeNode*> currentLevelNodes;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                totalSum += (node->left ? node->left->val : 0);
                totalSum += (node->right ? node->right->val : 0);
                
                currentLevelNodes.push_back(node);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            for (TreeNode* node : currentLevelNodes) {
                int siblingSum = 0;
                if (node->left && node->right) {
                    siblingSum = node->left->val + node->right->val;
                } else if (node->left) {
                    siblingSum = node->left->val;
                } else if (node->right) {
                    siblingSum = node->right->val;
                }
                if (node->left) {
                    node->left->val = totalSum - siblingSum;
                }
                if (node->right) {
                    node->right->val = totalSum - siblingSum;
                }
            }
        }
        
        return root;
    }
};
