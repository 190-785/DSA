class Solution {
public:
    double powed(double x, long long n, double res) {
        if (n == 0) return res;

        res = (n % 2 == 1) ? res * x : res;  
        return powed(x * x, n / 2, res);
    }

    double myPow(double x, int n) {
        double res = 1.0;
        long long num = n;
        
        if (num < 0) {
            x = 1.0 / x; 
            num = -num;
        }

        return powed(x, num, res);
    }
};
