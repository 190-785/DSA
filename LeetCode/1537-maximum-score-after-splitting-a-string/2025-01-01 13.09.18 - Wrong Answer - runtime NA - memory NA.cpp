class Solution {
public:
    int maxScore(string s) {
        int lzero = 0;
        int rone = 0;
        if (s[0] == '0')
            lzero++;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '1')
                rone++;
        }
        int maxScore = lzero + rone;
        for (int i = 1; i < s.size(); i++) {
            int score = 0;
            if (s[i] == '0') {
                lzero++;
            } else {
                rone--;
            }
            score = lzero + rone;
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};