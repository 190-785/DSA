class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0)
                remainder += k;
            remainderCount[remainder]++;
        }

        for (int num : arr) {
            int remainder = num % k;
            if (remainder < 0)
                remainder += k;

            if (remainder == 0) {
                if (remainderCount[remainder] % 2 != 0) {
                    return false;
                }
            }

            else if (2 * remainder == k) {
                if (remainderCount[remainder] % 2 != 0) {
                    return false;
                }
            } else {
                if (remainderCount[remainder] !=
                    remainderCount[k - remainder]) {
                    return false;
                }
            }
        }

        return true;
    }
};