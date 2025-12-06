class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mpp;
        int presum = 0;
        mpp.insert({0, 1});
        int count = 0;
        int rem = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            rem = presum - k;
            if (mpp.count(rem)) {
                count += mpp[rem];
            }
            if (mpp.count(presum)) {
                mpp[presum]++;
            } else {
                mpp.emplace(presum, 1);
            }
        }
        return count;
    }
};