class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n);
        long long prefix = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == 0)
                (prefix *= 2);
            else
                prefix = (prefix * 2) + 1;
            prefix%=5;
            if (prefix == 0)
                res[i] = true;
            else
                res[i] = false;
        }
        return res;
    }
};