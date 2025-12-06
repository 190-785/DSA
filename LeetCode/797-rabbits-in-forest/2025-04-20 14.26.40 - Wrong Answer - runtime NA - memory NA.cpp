class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        vector<int> freq(1000, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (freq[answers[i]] == 0) {
                freq[answers[i]] = answers[i] - 1;
                res += answers[i];
            } else {
                freq[answers[i]]--;
            }
        }
        return res + n - 2;
    }
};