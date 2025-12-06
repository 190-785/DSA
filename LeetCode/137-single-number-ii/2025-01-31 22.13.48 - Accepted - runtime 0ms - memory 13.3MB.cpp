class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twoes = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twoes;
            twoes = (twoes ^ nums[i]) & ~ones;
        }
        return ones;
    }
};