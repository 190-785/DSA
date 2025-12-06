class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        if (str1.size() > str2.size())
            return false;
        int n1 = str1.size();
        int n2 = str2.size();
        for (int i = 0; i < n1; i++) {
            if (str1[i] != str2[i])
                return false;
            if (str1[n1 - 1 - i] != str2[n2 - 1 - i])
                return false;
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    res++;
            }
        }
        return res;
    }
};
