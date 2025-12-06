class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        for (int i = 0; i < n;) {
            char currentChar = word[i];
            int count = 0;
            while (i < n && word[i] == currentChar) {
                count++;
                i++;
            }

            if (count > 1) {
                ans += (count - 1);
            }
        }

        return ans;
    }
};