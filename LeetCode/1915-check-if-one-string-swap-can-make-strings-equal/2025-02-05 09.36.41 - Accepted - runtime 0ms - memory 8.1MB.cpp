class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;
        int no = 0;
        pair<char, char> charry1, charry2;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (no == 2) return false;
                if (no == 0) charry1 = {s1[i], s2[i]};
                if (no == 1) charry2 = {s1[i], s2[i]};
                no++;
            }
        }

        return (no == 2 && charry1.first == charry2.second && charry1.second == charry2.first);
    }
};
