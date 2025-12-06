class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> uniqueXorValues;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int k = j; k < n; k++) {
                    int xorValue = nums[i] ^ nums[j] ^ nums[k];
                    uniqueXorValues.insert(xorValue);
                }
            }
        }

        return uniqueXorValues.size();
    }
};