class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0, alt = 1;
        bool prev;
        if (nums[0] % 2 == 0) {
            prev = true;
            even++;
        } else {
            prev = false;
            odd++;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even++;
                if (!prev) {
                    alt++;
                }
                prev = true;
            } else {
                odd++;
                if (prev) {
                    alt++;
                }
                prev = false;
            }
        }
        return max(alt, max(odd, even));
    }
};