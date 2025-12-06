class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = *(max_element(nums.begin(), nums.end()));
        if (n < 2)
            return 0;
        vector<int> primes(n + 1, 1);
        primes[0] = 0;
        primes[1] = 0;
        for (int i = 2; i <= sqrt(n); i++) {
            if (primes[i] == 1) {
                for (long long j = i * i; j <= n; j += i) {
                    primes[j] = 0;
                }
            }
        }
        int res = 0;
        int left = -1;
        int right = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (primes[nums[i]]) {
                if (left == -1) {
                    left = i;
                }
                right = i;
            }
        }
        if (left != -1 && right != -1) {
            res = right - left;
        }
        return res;
    }
};
