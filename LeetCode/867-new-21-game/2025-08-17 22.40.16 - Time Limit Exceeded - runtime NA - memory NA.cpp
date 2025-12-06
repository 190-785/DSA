class Solution {
public:
    double dfs(int score, int maxPts, int n, int k, vector<double>& cache) {
        if (score >= k) {
            if (score <= n)
                return 1.0;
            else
                return 0.0;
        }

        if (cache[score] != -1.0) {
            return cache[score];
        }

        double prob = 0.0;
        for (int i = 1; i <= maxPts; i++) {
            prob += dfs(score + i, maxPts, n, k, cache);
        }

        cache[score] = prob / maxPts;
        return cache[score];
    }

    double new21Game(int n, int k, int maxPts) {
        vector<double> cache(n + maxPts + 1, -1.0);
        return dfs(0, maxPts, n, k, cache);
    }
};
