class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        unordered_map<int, int> idToValue;
        for (const auto& pair : nums1) {
            int id = pair[0];
            int value = pair[1];
            idToValue[id] += value;
        }
        for (const auto& pair : nums2) {
            int id = pair[0];
            int value = pair[1];
            idToValue[id] += value;
        }

        vector<vector<int>> result;
        for (const auto& pair : idToValue) {
            result.push_back({pair.first, pair.second});
        }
        sort(result.begin(), result.end());

        return result;
    }
};
