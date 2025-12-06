class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelError;

        for (const string& word : wordlist) {
            string lower = toLower(word);
            if (caseInsensitive.find(lower) == caseInsensitive.end())
                caseInsensitive[lower] = word;

            string devoweled = devowel(lower);
            if (vowelError.find(devoweled) == vowelError.end())
                vowelError[devoweled] = word;
        }

        vector<string> result;
        for (const string& query : queries) {
            if (exact.count(query)) {
                result.push_back(query);
            } else {
                string lower = toLower(query);
                if (caseInsensitive.count(lower)) {
                    result.push_back(caseInsensitive[lower]);
                } else {
                    string devoweled = devowel(lower);
                    if (vowelError.count(devoweled)) {
                        result.push_back(vowelError[devoweled]);
                    } else {
                        result.push_back("");
                    }
                }
            }
        }

        return result;
    }

private:
    string toLower(const string& word) {
        string res = word;
        for (char& c : res) c = tolower(c);
        return res;
    }

    string devowel(const string& word) {
        string res = word;
        for (char& c : res) {
            if (isVowel(c)) c = '*';
        }
        return res;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
