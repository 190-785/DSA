class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int res = accumulate(nums.begin(), nums.end(), 0);
        if (res % 3 == 0)
            return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int remd = res % 3;
        cout << remd << endl;
        if (remd % 3 == 1) {
            if (nums[0] % 3 == 1)
                return res - nums[0];
            int forTwo = nums[0];
            int forOne = 0;
            for (int i = 1; i < n; i++) {
                if (nums[i] % 3 == 1)
                    return res - nums[i];
                if (nums[i] % 3 == 2)
                    return res - nums[i] - forTwo;
            }
        }
        int forTwo = 0, forOne = 0;
        if (nums[0] % 3 == 2)
            return res - nums[0];
        if (nums[0] % 3 == 1)
            forOne = nums[0];
        cout << forOne << " " << forTwo << endl;
        for (int i = 1; i < n; i++) {
            if (forTwo && forOne != 0 && forOne != nums[0])
                break;
            if (forOne == nums[0] && nums[i] % 3 == 1)
                forOne += nums[i];
            if (!forTwo && nums[i] % 3 == 2)
                forTwo = nums[i];
            cout << forOne << " " << forTwo << endl;
        }
        if (forOne != nums[0] && forOne)
            return res - min(forOne, forTwo);
        return res - forTwo;
    }
};