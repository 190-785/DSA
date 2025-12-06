class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int ind = events[0][0];
        int max_time = events[0][1];
        int n = events.size();
        for (int i = 1; i < n; i++) {
            int tem = events[i][1] - events[i - 1][1];
            if (max_time < tem) {
                ind = events[i][0];
                max_time = tem;
            } else if (max_time == tem) {
                if (ind > events[i][0]) {
                    ind = events[i][0];
                }
            }
        }
        return ind;
    }
};
