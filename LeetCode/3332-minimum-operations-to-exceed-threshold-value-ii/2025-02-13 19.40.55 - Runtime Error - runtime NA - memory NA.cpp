class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int ops = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
        }
        if (pq.top() >= k)
            return 0;
        while (pq.size() > 1 && pq.top() < k) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            int temp = (min(a, b)) * 2 + max(a, b);
            pq.pop();
            pq.push(temp);
            ops++;
        }
        return ops;
    }
};