class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        long long totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        int rem = totalSum % p;
        if (rem == 0) {
            return 0;
        }

        map<long long, int> mpp;
        mpp[0] = -1;
        int minLen = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            long long mod = sum % p;
            long long target = (mod - rem + p) % p;

            if (mpp.find(target) != mpp.end()) {
                minLen = min(minLen, i - mpp[target]);
            }

            mpp[mod] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};
