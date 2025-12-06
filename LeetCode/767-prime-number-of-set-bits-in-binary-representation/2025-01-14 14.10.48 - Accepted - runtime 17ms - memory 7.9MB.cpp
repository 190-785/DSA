class Solution {
public:
    int countBits(int num) {
        int count = 0;
        while (num != 0) {
            if (num & 1) {
                count++;
            }
            num >>= 1;
        }
        return count;
    }
    int isPrime(int num) {
        if (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 ||
            num == 13 || num == 17 || num == 19) {
            return true;
        }
        return false;
    }

    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (isPrime(countBits(i))) {
                count++;
            }
        }
        return count;
    }
};