class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if(sum<k) return sum;
        int remainder = sum % k;
        if (remainder == 0)
            return 0;
        int minOps = INT_MAX;
        for (int num : nums) {
            int reduction = num % k;
            if (reduction >= remainder) {
                minOps = min(minOps, remainder);
            } else {
                minOps = min(minOps, k - reduction + remainder);
            }
        }
        return minOps;
    }
};
