class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int minTime = INT_MAX;
        for (int i = 0; i < n; i++) {
            int time = tasks[i][0] + tasks[i][1];
            minTime = min(minTime, time);
        }
        return minTime;
    }
};