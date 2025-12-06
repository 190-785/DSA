class Solution {
public:
    void create(int node, int l, int r, const vector<int>& baskets,
                vector<int>& tree) {
        if (l == r) {
            tree[node] = baskets[l];
            return;
        }
        int mid = l + (r - l) / 2;
        create(node * 2, l, mid, baskets, tree);
        create(node * 2 + 1, mid + 1, r, baskets, tree);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
    int query(int node, int l, int r, int ql, int qr, const vector<int>& tree) {

    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> tree(4 * n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += query(1, 0, n - 1, fruits[i], INT_MAX)
        }
    }
};