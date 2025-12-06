class Solution {
public:
    vector<string> split(const string& sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() > sentence2.size()) {
            swap(sentence1, sentence2);
        }
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        int i = 0, j = 0;
        while (i < words1.size() && words1[i] == words2[i]) {
            i++;
        }
        while (j < words1.size() &&
               words1[words1.size() - 1 - j] == words2[words2.size() - 1 - j]) {
            j++;
        }
        return i + j >= words1.size();
    }
};