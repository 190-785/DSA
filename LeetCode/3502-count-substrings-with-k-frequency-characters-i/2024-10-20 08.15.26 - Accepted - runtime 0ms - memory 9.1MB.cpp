class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;
        vector<int> freq(26, 0);
        int left = 0;
        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++;
            while (true) {
                bool valid = false;
                for (int count : freq) {
                    if (count >= k) {
                        valid = true;
                        break;
                    }
                }
                if (valid) {
                    result += (n - right);
                    freq[s[left] - 'a']--;
                    left++;
                } else {
                    break;
                }
            }
        }
        return result;
    }
};
