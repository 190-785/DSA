class Solution {
public:
    vector<bool> sieve(int maxVal) {
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> isPrimeArr = sieve(maxVal);

        int count = 0;
        for (int i = 0; i < n; i++) {
            int minPrime = INT_MAX;
            int maxPrime = INT_MIN;
            int primeCount = 0;

            for (int j = i; j < n; j++) {
                int val = nums[j];
                if (isPrimeArr[val]) {
                    minPrime = min(minPrime, val);
                    maxPrime = max(maxPrime, val);
                    primeCount++;
                }
                if (primeCount >= 2 && maxPrime - minPrime <= k) {
                    count++;
                }
            }
        }
        return count;
    }
};
