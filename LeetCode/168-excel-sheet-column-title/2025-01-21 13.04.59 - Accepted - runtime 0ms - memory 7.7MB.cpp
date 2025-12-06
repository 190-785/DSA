class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber) {
            columnNumber--;
            res = char('A' + columnNumber % 26) + res;
            columnNumber /= 26;
        }
        return res;
    }
};