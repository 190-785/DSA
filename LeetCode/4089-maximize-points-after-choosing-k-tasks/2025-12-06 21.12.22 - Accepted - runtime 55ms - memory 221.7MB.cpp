class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2,
                        int k) {
        int n = technique1.size();
        long long res = 0;
        // So here we can just use a diff map
        // Sorting the map using the diff and compliting the tasks of tech 1
        // Which provide the max more points
        // i.e. first k tasks from sorted diff map
        if (k == n) {
            res = accumulate(technique1.begin(), technique1.end(), 0LL);
            return res;
        }
        vector<pair<int, int>> mpp;
        for (int i = 0; i < n; i++) {
            int diff = technique1[i] - technique2[i];
            mpp.push_back({i, diff});
        }
        sort(mpp.begin(), mpp.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });
        int Kdone = 0;
        // Yep my dumbass chose wrong as first and second in the loop below
        // And was like why is it not working?
        // Why out of bounds/overflow
        for (int i = 0; i < n; i++) {
            auto curr = mpp[i];
            int currIdx = curr.first;
            if (Kdone < k) {
                res += technique1[currIdx];
                Kdone++;
            } else {
                if (curr.second > 0)
                    res += technique1[currIdx];
                else
                    res += technique2[currIdx];
            }
        }
        return res;
    }
};