class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        long long sum = 0;
        for (int x : batteries)
            sum += x;
        for (int i = batteries.size() - 1; i >= 0; i--) {
            if (batteries[i] <= sum / n)
                return sum / n;
            sum -= batteries[i];
            n--;
        }
        return sum / n;
    }
};