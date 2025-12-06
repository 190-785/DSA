class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int Ones = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                swap(s[Ones], s[i]);
                Ones++;
            }
        }
        if (Ones > 0) {
            swap(s[Ones - 1], s[n - 1]);
        }

        return s;
    }
};
