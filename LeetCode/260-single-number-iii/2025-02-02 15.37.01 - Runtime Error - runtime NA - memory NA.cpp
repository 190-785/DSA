class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xore = 0;
        for (int i = 0; i < nums.size(); i++) {
            xore ^= nums[i];
        }
        // or use int bitone=xore&(-xore);
        int bitone = (xore & (xore - 1)) ^ xore;
        int bucketone = 0;
        int bucketzero = 0;
        cout << bitone;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & bitone)
                bucketone ^= nums[i];
            else
                bucketzero ^= nums[i];
        }
        return {bucketone, bucketzero};
    }
};