class FenwickTree {
private:
    vector<int> bitArray;
    int treeSize;

public:
    FenwickTree(int n) : treeSize(n), bitArray(n + 1, 0) {}
    void update(int i, int delta) {
        i++;
        while (i <= treeSize) {
            bitArray[i] += delta;
            i += i & (-i);
        }
    }
    int query(int idx) {
        if (idx < 0)
            return 0;
        idx++;
        int sum = 0;
        while (idx > 0) {
            sum += bitArray[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};
class Solution {

public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n), next(n);
        stack<int> mono;
        for (int i = 0; i < n; i++) {
            while (!mono.empty() && nums[mono.top()] <= nums[i]) {
                mono.pop();
            }
            prev[i] = mono.empty() ? -1 : mono.top();
            mono.push(i);
        }
        while (!mono.empty())
            mono.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!mono.empty() && nums[mono.top()] <= nums[i])
                mono.pop();
            next[i] = mono.empty() ? n : mono.top();
            mono.push(i);
        }
        vector<int> sortedIdx(n);
        iota(sortedIdx.begin(), sortedIdx.end(), 0);
        sort(sortedIdx.begin(), sortedIdx.end(),
             [&](int a, int b) { return nums[a] > nums[b]; });
        FenwickTree fenwickTree(n);
        long long res = 0;
        for (int i : sortedIdx) {
            int left = prev[i];
            int right = next[i];
            long long countL =
                fenwickTree.query(i - 1) - fenwickTree.query(left);
            long long countR =
                fenwickTree.query(right - 1) - fenwickTree.query(i);
            long long sizeL = (left != -1) ? countL + 1 : countL;
            long long sizeR = (right != n) ? 1 + countR : countR;
            res += sizeL * sizeR;
            fenwickTree.update(i, 1);
        }
        return res;
    }
};