class Solution {
public:
    void valid(int idx, string sub, int n, vector<string>& res) {
        if (sub.size() == n) {
            res.push_back(sub);
            return;
        }
        valid(idx + 1, sub + '1', n, res);

        if (sub.empty() || sub.back() != '0') {
            valid(idx + 1, sub + '0', n, res);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        valid(0, "", n, res);
        return res;
    }
};