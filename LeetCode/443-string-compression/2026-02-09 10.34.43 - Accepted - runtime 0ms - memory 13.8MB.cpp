class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0;
        int cnt = 1;
        int n = chars.size();

        for (int i = 0; i < n; i++) {
            if (i == n - 1 || chars[i] != chars[i + 1]) {
                chars[j] = chars[i];
                j++;

                if (cnt > 1) {
                    string s = to_string(cnt);
                    for (char c : s) {
                        chars[j] = c;
                        j++;
                    }
                }

                cnt = 1;
            } else {
                cnt++;
            }
        }
        return j;
    }
};