class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n+1, 0);
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += nums[i];
            sum[i+1] = temp;
        }
        
        int totalSum = sum[n];
        int count = 0;
        
        for (int i = 1; i < n; i++) {
            int leftSum = sum[i];
            int rightSum = totalSum - leftSum;
            if ((leftSum - rightSum) % 2 == 0) {
                count++;
            }
        }
        
        return count;
    }
};
