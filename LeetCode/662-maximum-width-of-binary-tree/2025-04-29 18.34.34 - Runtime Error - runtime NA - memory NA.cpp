class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            int minIndex = q.front().second;
            int first, last;

            for (int i = 0; i < size; i++) {
                int curr = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr;
                if (i == size - 1)
                    last = curr;

                if (node->left)
                    q.push({node->left, curr * 2 + 1});
                if (node->right)
                    q.push({node->right, curr * 2 + 2});
            }

            res = max(res, last - first + 1);
        }
        return res;
    }
};
