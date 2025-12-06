class Solution {
public:
    void findComb(int idx, string& temp, vector<string>& res,
                  const vector<string>& mapping, const string& digits) {
        if (idx == digits.size()) {
            res.push_back(temp);
            return;
        }
        int mapIndex = digits[idx] - '2';
        for (char ch : mapping[mapIndex]) {
            temp.push_back(ch);
            findComb(idx + 1, temp, res, mapping, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        vector<string> mapping = {"abc", "def",  "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        findComb(0, temp, res, mapping, digits);
        return res;
    }
};
