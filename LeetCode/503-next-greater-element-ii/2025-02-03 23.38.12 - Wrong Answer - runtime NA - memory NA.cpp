class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                nge[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }
            if (nge[i] == -1 && !stk.empty()) {
                nge[i] = stk.top();
            }
            stk.push(nums[i]);
        }

        return nge;
    }
};
