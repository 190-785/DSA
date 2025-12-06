class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xore = 0;
        for (int i = 0; i < nums.size(); i++) {
            xore ^= nums[i];
        }
        // or use int bitone=xore&(-xore); 
        //cannot be stored in an integer variable 10^-31-1
        long long bitone = (xore & (xore - 1)) ^ xore;
        long long bucketone = 0;
        long long bucketzero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & bitone)
                bucketone ^= nums[i];
            else
                bucketzero ^= nums[i];
        }
        return {static_cast<int>(bucketone), static_cast<int>(bucketzero)};
    }
};
