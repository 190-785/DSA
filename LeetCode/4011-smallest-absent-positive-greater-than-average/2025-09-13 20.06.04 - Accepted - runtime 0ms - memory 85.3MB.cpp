class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int avg = sum / n;
        int can = avg + 1;
        while (true) {
            bool found = false;
            for (int num : nums) {
                if (num == can) {
                    found = true;
                    break;
                }
            }
            if (!found && can > 0)
                return can;
            can++;
        }
        return -1;
    }
};