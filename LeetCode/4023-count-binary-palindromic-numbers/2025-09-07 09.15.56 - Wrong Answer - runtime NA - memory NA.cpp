class Solution {
public:
    long long createPal(long long half, bool isOdd) {
        long long res = half;
        long long temp = isOdd ? (half >> 1) : half;
        while (temp > 0) {
            res <<= 1;
            res |= (temp & 1);
            temp >>= 1;
        }
        return res;
    }
    int countBinaryPalindromes(long long n) {
        int count = 1;
        int half = 1;
        while (half < n) {
            bool oddMoreThanN = false;
            bool evenMoreThanN = false;
            long long oddPal = createPal(half, true);
            if (oddPal > n) {
                oddMoreThanN = true;
            } else {
                count++;
            }
            long long evenPal = createPal(half, false);
            if (evenPal > n) {
                evenMoreThanN = true;
            } else {
                count++;
            }
            if (oddMoreThanN && evenMoreThanN)
                break;
            half++;
        }
        return count;
    }
};