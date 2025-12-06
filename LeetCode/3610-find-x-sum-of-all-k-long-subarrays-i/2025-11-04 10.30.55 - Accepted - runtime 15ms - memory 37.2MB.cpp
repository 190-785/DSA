class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i <= n - k; ++i) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }
            priority_queue<pair<int, int>> pq;
            for (auto& [num, count] : freq) {
                pq.push({count, num});
            }
            int sum = 0;
            int count = 0;
            while (!pq.empty() && count < x) {
                auto [freq, num] = pq.top();
                pq.pop();
                sum += num * freq;
                count++;
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};