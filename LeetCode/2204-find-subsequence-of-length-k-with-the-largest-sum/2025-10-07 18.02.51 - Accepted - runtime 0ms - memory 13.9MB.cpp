class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i], i});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<pair<int, int>> topEl;
        while (!minHeap.empty()) {
            topEl.push_back(minHeap.top());
            minHeap.pop();
        }

        sort(topEl.begin(), topEl.end(),
             [](auto& a, auto& b) { return a.second < b.second; });

        vector<int> res;
        for (auto& p : topEl) {
            res.push_back(p.first);
        }
        return res;
    }
};