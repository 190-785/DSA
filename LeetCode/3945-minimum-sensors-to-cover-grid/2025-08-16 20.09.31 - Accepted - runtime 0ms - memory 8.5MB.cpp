class Solution {
public:
    int minSensors(int n, int m, int k) {
        int cheD = (2 * k) + 1;
        int sen_N = (n + cheD - 1) / cheD;
        int sen_M = (m + cheD - 1) / cheD;
        int total = sen_N * sen_M;
        return total;
    }
};