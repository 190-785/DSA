class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        if (n < 4)
            return 0;

        vector<pair<int, int>> intervals;
        vector<vector<int>> pos(26);

        for (int i = 0; i < n; i++) {
            pos[word[i] - 'a'].push_back(i);
        }

        for (int j = 0; j < 26; j++) {
            if (pos[j].empty())
                continue;

            for (int i = 0; i < pos[j].size(); i++) {
                int start = pos[j][i], target = start + 3;
                auto it = lower_bound(pos[j].begin(), pos[j].end(), target);

                if (it != pos[j].end())
                    intervals.push_back({start, *it});
            }
        }

        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        int count = 0, last_end = -1;
        for (auto& interval : intervals) {
            if (interval.first > last_end) {
                count++;
                last_end = interval.second;
            }
        }
        return count;
    }
};
