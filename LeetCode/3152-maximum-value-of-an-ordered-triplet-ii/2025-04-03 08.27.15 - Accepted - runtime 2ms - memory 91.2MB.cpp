class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        //maxi= max value of nums[i]
        //maxd= max value of the difference between nums[i] and nums[j]
        int maxi = 0, maxd = 0;
        long long res = 0;
        int n = nums.size();
        for (int k = 0; k < n; k++) {
            //Finding the maximum result
            res = max(res, (long long)maxd * nums[k]);
            //updating maxd accordingly [as in updating the value of j]
            maxd = max(maxd, maxi - nums[k]);
            //updating the value fo maxi [as in updating the value of i]
            maxi = max(maxi, nums[k]);
        }
        return res;
    }
};