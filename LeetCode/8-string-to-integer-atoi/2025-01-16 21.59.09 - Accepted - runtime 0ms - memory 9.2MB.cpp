class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        long long result = 0;
        int sign = 1;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            i++;
            if (result > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        return result * sign;
    }
};
