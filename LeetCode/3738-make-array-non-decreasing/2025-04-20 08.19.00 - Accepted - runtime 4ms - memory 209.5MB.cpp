class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty() && stack.back() > num) {
                int val = stack.back();
                stack.pop_back();
                num = max(num, val);  
            }
            stack.push_back(num);
        }

        return stack.size();
    }
};
