class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                diff[start]++;
                if (end + 1 < n) diff[end + 1]--;
            } else {
                diff[start]--;
                if (end + 1 < n) diff[end + 1]++;
            }
        }

        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift = (shift + diff[i] + 26) % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }

        return s;
    }
};
