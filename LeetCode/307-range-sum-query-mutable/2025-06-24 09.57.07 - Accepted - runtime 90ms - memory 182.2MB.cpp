class NumArray {
private:
    vector<int> tree;
    int n;

    void create(int node, int l, int r, const vector<int>& nums) {
        if (l == r) {
            tree[node] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        create(node * 2, l, mid, nums);
        create(2 * node + 1, mid + 1, r, nums);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update_tree(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update_tree(node * 2, l, mid, idx, val);
        } else {
            update_tree(2 * node + 1, mid + 1, r, idx, val);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && qr >= r)
            return tree[node];
        else {
            int mid = l + (r - l) / 2;
            int lefts = query(2 * node, l, mid, ql, qr);
            int rights = query(2 * node + 1, mid + 1, r, ql, qr);
            return lefts + rights;
        }
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, 0);
        create(1, 0, n - 1, nums);
    }

    void update(int index, int val) { update_tree(1, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */