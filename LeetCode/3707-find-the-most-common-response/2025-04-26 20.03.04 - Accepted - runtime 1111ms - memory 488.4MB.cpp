class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> freqMap;

        for (auto& dayRes : responses) {
            set<string> uniRes(dayRes.begin(), dayRes.end());
            for (const string& response : uniRes) {
                freqMap[response]++;
            }
        }
        string mostCommon = "";
        int maxCount = 0;

        for (const auto& [response, count] : freqMap) {
            if (count > maxCount ||
                (count == maxCount && response < mostCommon)) {
                mostCommon = response;
                maxCount = count;
            }
        }

        return mostCommon;
    }
};
