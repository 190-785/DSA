class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string result = "";
        for (int i = 0; i < strs.size(); i++) {
            char str = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != str)
                    return result;
            }
            result += str;
        }
        return result;
    }
};