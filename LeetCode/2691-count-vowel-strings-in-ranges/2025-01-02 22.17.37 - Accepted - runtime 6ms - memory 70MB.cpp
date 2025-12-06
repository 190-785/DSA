class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size() + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < words.size(); i++) {
            prefixSum[i + 1] = prefixSum[i];
            if (vowels.count(words[i][0]) && vowels.count(words[i].back())) {
                prefixSum[i + 1]++;
            }
        }

        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            result.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        return result;
    }
};
