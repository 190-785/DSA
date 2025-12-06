class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        string left_half = "", middle = "";

        for (auto& [ch, count] : freq) {
            int half_count = count / 2;
            left_half += string(half_count, ch);
            if (count % 2 == 1) {
                middle = ch;
            }
        }

        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        return left_half + middle + right_half;
    }
};
