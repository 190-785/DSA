class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (isPrime(i))
                res -= nums[i];
            else
                res += nums[i];
        }
        return abs(res);
    }
};