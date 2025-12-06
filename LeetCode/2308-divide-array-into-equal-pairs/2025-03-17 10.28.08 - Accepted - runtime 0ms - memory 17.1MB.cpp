class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> freq(501);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (int i = 1; i < freq.size(); i++) {
            if ((freq[i] % 2) != 0)
                return false;
        }
        return true;
    }
};