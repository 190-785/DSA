class Solution {
public:
    bool isSymmetric(string num) {
        int n = num.size();
        if (n % 2 != 0)
            return false;
        int res = 0;
        for (int i = 0; i < num.size() / 2; i++) {
            res = res + static_cast<int>(num[i]);
            res = res - static_cast<int>(num[n - i - 1]);
        }
        return !res;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            if (isSymmetric(to_string(i)))
                cnt++;
        }
        return cnt;
    }
};