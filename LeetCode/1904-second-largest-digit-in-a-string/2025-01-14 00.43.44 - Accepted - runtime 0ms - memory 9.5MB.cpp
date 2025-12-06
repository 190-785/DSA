class Solution {
public:
    int secondHighest(string s) {
        int n1 = -1;
        int n2 = -1;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                if (num > n1) {
                    n2 = n1;
                    n1 = num;
                } else if (num > n2 && num < n1) {
                    n2 = num;
                }
            }
        }
        return n2;
    }
};