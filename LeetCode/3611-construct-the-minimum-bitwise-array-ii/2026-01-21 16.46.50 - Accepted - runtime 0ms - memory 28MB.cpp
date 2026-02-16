class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            int ans = -1;
            int d = 1;
            while ((x & d) != 0) {
                ans = x - d;
                d <<= 1;
            }
            x = ans;
        }
        return nums;
    }
};