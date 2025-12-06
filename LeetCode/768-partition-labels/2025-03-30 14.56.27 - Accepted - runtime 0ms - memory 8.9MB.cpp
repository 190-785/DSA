class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> res;
        int left = 0, right = 0;
        while (left < n) {
            char c = s[left];
            right = last[c - 'a'];
            int i = left;
            while (i <= right) {
                if ((last[s[i] - 'a']) > right)
                    right = last[s[i] - 'a'];
                i++;
            }
            res.push_back(right - left + 1);
            left = right + 1;
        }
        return res;
    }
};