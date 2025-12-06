class Solution {
public:
    int smallestNumber(int n, int t) {
        auto product_of_digits = [](int num) {
            int product = 1;
            while (num > 0) {
                int digit = num % 10;
                product *= digit;
                num /= 10;
            }
            return product;
        };

        while (true) {
            if (product_of_digits(n) % t == 0) {
                return n;
            }
            n++;
        }
    }
};
