class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            int minj = max(0, n - i - limit);
            int maxj = min(limit, n - i);
            if (maxj >= minj)
                count += (maxj - minj + 1);
        }
        return count;
    }
};