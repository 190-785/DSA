class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0)
            return false;
        int open = 0, wildcards = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(')
                    open++;
                else
                    open--;
            } else {
                wildcards++;
            }
            if (open + wildcards < 0)
                return false;
        }
        int close = 0;
        wildcards = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                if (s[i] == ')')
                    close++;
                else
                    close--;
            } else {
                wildcards++;
            }
            if (close + wildcards < 0)
                return false;
        }

        return true;
    }
};
