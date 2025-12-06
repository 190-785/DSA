class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> lastBitPos(32, -1);

        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    lastBitPos[bit] = i;
                }
            }

            int last = i;
            for (int bit = 0; bit < 32; bit++) {
                last = max(last, lastBitPos[bit]);
            }

            res[i] = last - i + 1;
        }

        return res;
    }
};
