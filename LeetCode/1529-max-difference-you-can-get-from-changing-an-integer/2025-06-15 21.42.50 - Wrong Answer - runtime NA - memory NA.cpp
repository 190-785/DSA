class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxNum = s, minNum = s;

        char targetMax = ' ';
        for (char c : s) {
            if (c != '9') {
                targetMax = c;
                break;
            }
        }
        if (targetMax != ' ') {
            for (char &c : maxNum) {
                if (c == targetMax) {
                    c = '9';
                }
            }
        }

        char targetMin = minNum[0]; 
        char replacementMin = (targetMin == '1') ? '0' : '1';
        for (char &c : minNum) {
            if (c == targetMin) {
                c = replacementMin;
            }
        }

        return stoi(maxNum) - stoi(minNum);
    }
};
