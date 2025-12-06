class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        stack<int> st;
        for (auto& p : freq)
            st.push(p.second);

        vector<int> counts;
        while (!st.empty()) {
            counts.push_back(st.top());
            st.pop();
        }

        sort(counts.begin(), counts.end());

        int deletions = 0;
        while (counts.size() > k) {
            deletions += counts[0];
            counts.erase(counts.begin());
        }
        return deletions;
    }
};