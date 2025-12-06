class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (k == 0)
            return nums;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; i++) {
            auto num = pq.top();
            pq.pop();
            num.first *= multiplier;
            pq.push(num);
        }
        vector<int> res(n);
        while (!pq.empty()) {
            auto num = pq.top();
            pq.pop();
            res[num.second] = num.first;
        }
        return res;
    }
};