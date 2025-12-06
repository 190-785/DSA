class Solution {
public:
    bool fP(int sIdx, int sum, string sNum, int t, vector<vector<int>>& memo) {
        if (sIdx == sNum.size()) {
            return sum == t;
        }

        if (sum > t)
            return false;

        if (memo[sIdx][sum] != -1)
            return memo[sIdx][sum];

        bool pF = false;

        for (int cIdx = sIdx; cIdx < sNum.size(); cIdx++) {
            string cStr = sNum.substr(sIdx, cIdx - sIdx + 1);
            int add = stoi(cStr);

            pF = pF || fP(cIdx + 1, sum + add, sNum, t, memo);
            if (pF == true)
                return true;
        }

        return memo[sIdx][sum] = pF;
    }

    int punishmentNumber(int n) {
        int pNum = 0;
        for (int cNum = 1; cNum <= n; cNum++) {
            int sNum = cNum * cNum;
            string sNumStr = to_string(sNum);

            vector<vector<int>> memo(sNumStr.size(), vector<int>(cNum + 1, -1));

            if (fP(0, 0, sNumStr, cNum, memo)) {
                pNum += sNum;
            }
        }
        return pNum;
    }
};
