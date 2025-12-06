class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int maxFreq = *max_element(freq.begin(), freq.end());
        if (maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
            }
        }

        string res;
        while (pq.size() > 1) {
            auto [freq1, char1] = pq.top();
            pq.pop();
            auto [freq2, char2] = pq.top();
            pq.pop();
            res += char1;
            res += char2;
            if (--freq1 > 0)
                pq.push({freq1, char1});
            if (--freq2 > 0)
                pq.push({freq2, char2});
        }
        if (!pq.empty()) {
            auto [freq, char_] = pq.top();
            if (freq > 1) {
                return "";
            }
            res += char_;
        }

        return res;
    }
};
