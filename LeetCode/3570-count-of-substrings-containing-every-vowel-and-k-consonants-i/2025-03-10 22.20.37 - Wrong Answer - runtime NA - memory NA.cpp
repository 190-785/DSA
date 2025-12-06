class Solution {
public:
    int countOfSubstrings(string word, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> charCount;
        int consonantCount = 0, vowelCount = 0, result = 0;
        int left = 0;

        for (int right = 0; right < word.size(); ++right) {
            char currentChar = word[right];

            charCount[currentChar]++;
            if (vowels.count(currentChar)) {
                if (charCount[currentChar] == 1) {
                    vowelCount++;
                }
            } else {
                consonantCount++;
            }

            while (consonantCount > k) {
                char leftChar = word[left];
                charCount[leftChar]--;
                if (vowels.count(leftChar)) {
                    if (charCount[leftChar] == 0) {
                        vowelCount--;
                    }
                } else {
                    consonantCount--;
                }
                left++;
            }
            if (vowelCount == 5 && consonantCount == k) {
                result++;
            }
        }

        return result;
    }
};
