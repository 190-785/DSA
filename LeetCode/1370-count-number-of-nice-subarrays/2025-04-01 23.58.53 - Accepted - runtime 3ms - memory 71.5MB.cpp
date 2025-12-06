class Solution {
public:
    int numSub(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        int l = 0, r = 0;
        int cnt = 0, oddCnt = 0;
        while (r < nums.size()) {
            if (nums[r] % 2 != 0) {
                oddCnt++;
                while (oddCnt > k) {
                    if (nums[l] % 2 != 0) {
                        oddCnt--;
                    }
                    l++;
                }
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSub(nums, k) - numSub(nums, k - 1);
    }
};
