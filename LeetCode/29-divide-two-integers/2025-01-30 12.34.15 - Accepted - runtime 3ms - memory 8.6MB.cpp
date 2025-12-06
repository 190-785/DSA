class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend; 
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX; 
            return -dividend;
        }

        bool sign = (dividend < 0) == (divisor < 0);
        long long divid = abs((long long)dividend);
        long long divis = abs((long long)divisor);
        int ans = 0;

        while (divid >= divis) {
            long long temp = divis, multiple = 1;
            while (divid >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            divid -= temp;
            ans += multiple;
        }

        return sign ? ans : -ans;
    }
};
