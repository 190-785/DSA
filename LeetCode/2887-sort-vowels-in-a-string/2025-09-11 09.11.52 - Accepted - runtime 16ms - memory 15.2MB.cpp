class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        vector<int> vowFreq(10, 0);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            auto it = find(vowels.begin(), vowels.end(), s[i]);
            if (it != vowels.end()) {
                vowFreq[distance(vowels.begin(), it)]++;
            }
        }

        string res = s;
        int last = 0;
        for (int i = 0; i < n; i++) {
            auto it = find(vowels.begin(), vowels.end(), s[i]);
            if (it != vowels.end()) {
                while (vowFreq[last] == 0) {
                    last++;
                }
                res[i] = vowels[last];
                vowFreq[last]--;
            }
        }
        return res;
    }
};