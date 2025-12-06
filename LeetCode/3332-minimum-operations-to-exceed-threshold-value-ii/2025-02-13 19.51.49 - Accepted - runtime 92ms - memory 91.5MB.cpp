class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)
            return 0;
        int ops = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        while (pq.size() > 1 && pq.top() < k) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            long long temp = static_cast<long long>(a) * 2 + static_cast<long long>(b);
            pq.push(temp);
            ops++;
        }
        return ops;
    }
};
