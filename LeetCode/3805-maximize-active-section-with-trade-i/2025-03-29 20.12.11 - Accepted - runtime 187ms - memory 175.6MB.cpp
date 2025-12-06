class Solution {
public:
    int maxActiveSectionsAfterTrade(string inputStr) {
        int n = inputStr.size();
        int activeCnt = 0;
        for (char c : inputStr)
            if (c == '1')
                activeCnt++;
        if (inputStr.find('0') == string::npos ||
            inputStr.find('1') == string::npos)
            return activeCnt;
        string augStr = "1" + inputStr + "1";
        int m = augStr.size();
        vector<pair<char, int>> blocks;
        for (int i = 0; i < m;) {
            char ch = augStr[i];
            int j = i;
            while (j < m && augStr[j] == ch)
                j++;
            blocks.push_back({ch, j - i});
            i = j;
        }
        int maxGain = 0;
        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' && blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0')
                maxGain =
                    max(maxGain, blocks[i - 1].second + blocks[i + 1].second);
        }
        return activeCnt + maxGain;
    }
};
