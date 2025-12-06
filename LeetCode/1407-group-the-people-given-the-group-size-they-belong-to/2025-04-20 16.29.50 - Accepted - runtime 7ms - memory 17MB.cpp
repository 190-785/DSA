class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> freq;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++) {
            freq[groupSizes[i]].push_back(i);
        }
        for (auto& pair : freq) {
            int groupSize = pair.first;
            vector<int>& people = pair.second;
            for (int i = 0; i < people.size(); i += groupSize) {
                res.push_back(vector<int>(people.begin() + i,
                                          people.begin() + groupSize + i));
            }
        }
        return res;
    }
};