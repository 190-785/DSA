class Solution {
public:
    bool isPrime(long long num) {
        if (num < 2)
            return false;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    long long sumOfLargestPrimes(string s) {
        int n = s.size();
        unordered_set<long long> primeSet;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long num = stoll(s.substr(i, j - i + 1));
                if (isPrime(num))
                    primeSet.insert(num);
            }
        }
        vector<long long> primes(primeSet.begin(), primeSet.end());
        sort(primes.begin(), primes.end(), greater<long long>());
        long long sum = 0;
        for (int i = 0; i < min(3, (int)primes.size()); i++)
            sum += primes[i];
        return sum;
    }
};
