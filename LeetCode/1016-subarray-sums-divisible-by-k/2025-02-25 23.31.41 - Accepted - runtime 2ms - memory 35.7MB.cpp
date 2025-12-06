class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainder_count;
        remainder_count[0] = 1;
        int current_sum = 0;
        int result = 0;

        for (int num : nums) {
            current_sum += num;
            int remainder = ((current_sum % k) + k) % k;
            if (remainder_count.find(remainder) != remainder_count.end()) {
                result += remainder_count[remainder];
            }
            remainder_count[remainder]++;
        }

        return result;
    }
};
