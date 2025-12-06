class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const int MOD = 1e9 + 7;
        int n = conversions.size() + 1;
        vector<long long> bUnit(n, 1);
        vector<vector<pair<int, int>>> graph(n);
        for (auto& conv : conversions) {
            int src = conv[0], tgt = conv[1], factor = conv[2];
            graph[src].push_back({tgt, factor});
        }

        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int unit = q.front();
            q.pop();
            for (auto& [nextUnit, factor] : graph[unit]) {
                if (bUnit[nextUnit] == 1) {
                    bUnit[nextUnit] = (bUnit[unit] * factor) % MOD;
                    q.push(nextUnit);
                }
            }
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = static_cast<int>(bUnit[i]);
        }
        return res;
    }
};
