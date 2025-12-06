class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            for (int i = start; i <= end; ++i) {
                if (direction == 1) {
                    s[i] = (s[i] - 'a' + 1) % 26 + 'a';
                } else {
                    s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a';
                }
            }
        }
        return s;
    }
};
