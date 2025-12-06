class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> appear((1 << n) + 1, 0);
        for (int i = 0; i < n; i++) {
            bitset<16> bits(nums[i]);
            unsigned long decimal_value = bits.to_ulong();
            appear[decimal_value] = 1;
        }
        long long ans = 0;
        for (int i = (1 << (n - 1)); i < 1 << n; i++) {
            if (appear[i] == 0) {
                ans = i;
                break;
            }
        }
        string res = "";
        for (int i = 0; i < n; i++) {
            res = char('0' + (ans % 2)) + res;
            ans = ans / 2;
        }
        return res;
    }
};