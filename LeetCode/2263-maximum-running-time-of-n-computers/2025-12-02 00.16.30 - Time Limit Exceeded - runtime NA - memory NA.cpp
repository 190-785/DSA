class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for (int x : batteries)
            sum += x;
        long long left = 1;
        long long right = sum / n;
        while (left < right) {
            int mid = right - (right - left) / 2;
            long long extra = 0;
            for (int x : batteries)
                extra += min(x, mid);
            if (extra >= (long long)(n * mid))
                left = mid;
            else
                right - mid - 1;
        }
        return left;
    }
};