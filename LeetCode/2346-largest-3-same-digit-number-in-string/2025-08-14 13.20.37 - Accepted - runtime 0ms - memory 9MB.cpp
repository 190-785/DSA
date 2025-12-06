class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int last = -1;
        for (int i = 0; i < n - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                last = max(last, (int)num[i]);
            }
        }
        if (last != -1) {
            return string(3, (char)last);
        }
        return "";
    }
};