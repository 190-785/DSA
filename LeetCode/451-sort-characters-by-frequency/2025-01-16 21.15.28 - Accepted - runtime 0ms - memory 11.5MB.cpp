class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& [ch, f] : freq) {
            pq.push({f, ch});
        }
        string result;
        while (!pq.empty()) {
            auto [f, ch] = pq.top();
            pq.pop();
            result += string(f, ch);
        }

        return result;
    }
};
