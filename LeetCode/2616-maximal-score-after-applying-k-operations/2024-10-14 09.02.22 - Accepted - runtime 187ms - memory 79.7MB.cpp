class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        long long score = 0;
        while (k) {
            double operation = pq.top();
            pq.pop();
            score += operation;
            operation = ceil(operation / 3);
            pq.push(operation);
            k--;
        }
        return score;
    }
};