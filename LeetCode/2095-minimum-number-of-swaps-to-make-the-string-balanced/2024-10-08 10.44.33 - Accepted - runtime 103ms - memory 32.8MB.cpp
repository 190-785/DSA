class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        int maxE = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                count++;
                maxE = max(maxE, count);

            } else {
                count--;
            }
        }

        return ((maxE + 1) / 2);
    }
};