class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;
                int maxE = 0;
                int minE = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxE = max(maxE, freq[k]);
                        minE = min(minE, freq[k]);
                    }
                }
                sum += maxE - minE;
            }
        }
        return sum;
    }
};
