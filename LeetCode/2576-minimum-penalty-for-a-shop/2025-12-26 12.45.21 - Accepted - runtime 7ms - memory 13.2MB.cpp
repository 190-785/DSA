class Solution {
public:
    int bestClosingTime(string customers) {
        int res = 0;
        int n = customers.size();
        int penalty = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y')
                penalty++;
        }
        int minPenalty = penalty;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N')
                penalty++;
            else
                penalty--;
            if (penalty < minPenalty) {
                minPenalty = penalty;
                res = i + 1;
            }
        }
        return res;
    }
};