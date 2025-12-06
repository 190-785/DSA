class Solution {
public:
    bool canBeTyped(const string& word, const unordered_set<char>& row) {
        for (char c : word) {
            if (row.find(tolower(c)) == row.end()) {
                return false;
            }
        }
        return true;
    }

    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't',
                                    'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g',
                                    'h', 'j', 'k', 'l'};
        unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        vector<string> result;
        for (const string& word : words) {
            if (canBeTyped(word, row1) || canBeTyped(word, row2) ||
                canBeTyped(word, row3)) {
                result.push_back(word);
            }
        }
        return result;
    }
};
