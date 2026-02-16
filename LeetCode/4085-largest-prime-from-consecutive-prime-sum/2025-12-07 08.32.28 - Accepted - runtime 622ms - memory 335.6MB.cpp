class Solution {
public:
    int largestPrime(int n) {
        if(n<2) return 0;
        vector<int> seive(n + 1, 1);
        seive[0] = 0;
        seive[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (seive[i]) {
                for (int j = i * i; j <= n; j += i) {
                    seive[j] = 0;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i < n; i++) {
            if (seive[i])
                primes.push_back(i);
        }
        long long sum = 0;
        long long res = 2;
        for (int x : primes) {
            sum += x;
            if (sum > n)
                break;
            if (seive[sum])
                res = sum;
        }
        return static_cast<int>(res);
    }
};