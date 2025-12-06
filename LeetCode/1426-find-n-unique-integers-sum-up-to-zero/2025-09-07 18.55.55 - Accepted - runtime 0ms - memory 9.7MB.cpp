class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int mid = n / 2;
        for (int i = 0; i < mid; i++) {
            res[i] = -(i + 1);
        }
        for (int i = mid; i < n; i++) {
            res[i] = i - mid + 1;
        }
        if (n % 2 != 0)
            res[n - 1] = 0;
        return res;
    }
};