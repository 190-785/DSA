class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for (int i = 0; i < s.size(); i += k) {
            string group = s.substr(i, k);
            while (group.size() < k) {
                group += fill;
            }
            result.push_back(group);
        }
        return result;
    }
};
