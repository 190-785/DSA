class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size();
        vector<int> res(n);
        int m = potions.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++) {
            int curr = spells[i];
            int low = 0, high = m;
            int currRes = -1;
            while (low < high) {
                int mid = low + (high - low) / 2;
                long long prod = static_cast<long long>(curr) * potions[mid];
                if (prod < success)
                    low = mid + 1;
                else
                    high = mid;
            }
            res[i] = m - high;
        }
        return res;
    }
};