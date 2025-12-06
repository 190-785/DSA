class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps = 0;
        long long Zeroes = 0;
        int n = s.size();
        for (int i = (n - 1); i >= 0; i--) {
            if (s[i] == '0') {
                Zeroes++;
            } else {
                swaps += Zeroes;
            }
        }
        return swaps;
    }
};