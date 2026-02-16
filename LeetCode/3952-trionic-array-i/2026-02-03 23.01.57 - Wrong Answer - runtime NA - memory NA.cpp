class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        int p = -1, q = -1;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1])
                return false;
            if (state == 0) {
                if (nums[i] < nums[i + 1]) {
                    p = i + 1;
                    continue;
                } else {
                    if (p == -1)
                        return false;
                    state++;
                }
            } else if (state == 1) {
                if (nums[i] > nums[i + 1]) {
                    q = i + 1;
                    continue;
                } else {
                    if (q == -1)
                        return false;
                    state++;
                }
            } else {
                if (nums[i] > nums[i + 1])
                    return false;
            }
        }
        //cout << p << " " << q;
        return (p == -q || q == -q || q == n - 1 || p == n - 1 || p == q - 1)
                   ? false
                   : true;
    }
};