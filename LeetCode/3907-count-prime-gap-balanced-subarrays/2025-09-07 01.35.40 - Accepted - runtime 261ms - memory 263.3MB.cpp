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

        vector<pair<int, int>> primes;
        for (int i = 0; i < n; i++) {
            if (isPrimeArr[nums[i]]) {
                primes.push_back({nums[i], i});
            }
        }

        int m = primes.size();
        if (m < 2)
            return 0;

        int count = 0;
        int l = 0;
        deque<int> minDeque, maxDeque;

        for (int r = 0; r < m; r++) {
            int val = primes[r].first;

            while (!minDeque.empty() && primes[minDeque.back()].first >= val)
                minDeque.pop_back();
            minDeque.push_back(r);

            while (!maxDeque.empty() && primes[maxDeque.back()].first <= val)
                maxDeque.pop_back();
            maxDeque.push_back(r);

            while (!minDeque.empty() && !maxDeque.empty() &&
                   primes[maxDeque.front()].first -
                           primes[minDeque.front()].first >
                       k) {
                if (minDeque.front() == l)
                    minDeque.pop_front();
                if (maxDeque.front() == l)
                    maxDeque.pop_front();
                l++;
            }

            if (r - l + 1 >= 2) {
                int leftPrimeIdx = primes[r - 1].second;
                int rightPrimeIdx = primes[r].second;

                int prevPrimeIdx = (l == 0 ? -1 : primes[l - 1].second);
                int nextPrimeIdx = (r == m - 1 ? n : primes[r + 1].second);

                int choicesLeft = leftPrimeIdx - prevPrimeIdx;
                int choicesRight = nextPrimeIdx - rightPrimeIdx;

                count += choicesLeft * choicesRight;
            }
        }

        return count;
    }
};
