class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> res;
        vector<int> freq(10);
        for (int i : digits) {
            freq[i]++;
        }
        for (int i = 1; i < 10; i++) {
            if (freq[i] == 0)
                continue;
            freq[i]--;
            for (int j = 0; j < 10; j++) {
                if (freq[j] == 0)
                    continue;
                freq[j]--;
                for (int k = 0; k < 10; k += 2) {
                    if (freq[k] == 0)
                        continue;
                    res.push_back(i *100 + j * 10 + k);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        return res.size();
    }
};