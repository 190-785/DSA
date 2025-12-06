class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t) return t;
        unordered_map<char, int> freq;
        for (char c : t) {
            freq[c]++;
        }
        int l = 0, r = 0;
        int start = 0, minLen = INT_MAX;
        int n = s.size();
        int req = freq.size();
        int formed = 0;
        unordered_map<char, int> window;
        while (r < n) {
            window[s[r]]++;
            if (freq.count(s[r]) && window[s[r]] == freq[s[r]]) {
                formed++;
            }
            while (formed == req) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                window[s[l]]--;
                if (freq.count(s[l]) && window[s[l]] < freq[s[l]]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};