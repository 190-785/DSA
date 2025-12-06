class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        map<int, int> label;
        map<int, int> colors;
        int distinct = 0;

        for (int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0];
            int color = queries[i][1];
            if (label.find(ball) != label.end()) {
                int oldColor = label[ball];
                if (--colors[oldColor] == 0) {
                    distinct--;
                }
            }
            label[ball] = color;
            if (++colors[color] == 1) {
                distinct++;
            }
            res.push_back(distinct);
        }
        return res;
    }
};
