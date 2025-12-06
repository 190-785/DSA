class Solution {
public:
    bool isHappy(int n) {
        auto getNext = [](int number) {
            int total_sum = 0;
            while (number > 0) {
                int digit = number % 10;
                total_sum += digit * digit;
                number /= 10;
            }
            return total_sum;
        };

        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }
};
