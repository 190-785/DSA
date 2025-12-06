class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> freq(201, {0, 0});
        for (int num : nums) {
            freq[num + 100].first = num;
            freq[num + 100].second++;
        }
        vector<pair<int, int>> NonZeroFreq;
        for (auto& p : freq) {
            if (p.second > 0)
                NonZeroFreq.push_back(p);
        }

        sort(NonZeroFreq.begin(), NonZeroFreq.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 if (a.second == b.second)
                     return a.first > b.first;
                 return a.second < b.second;
             });
        vector<int> result;
        for (auto& p : NonZeroFreq) {
            result.insert(result.end(), p.second, p.first);
        }

        return result;
    }
};
