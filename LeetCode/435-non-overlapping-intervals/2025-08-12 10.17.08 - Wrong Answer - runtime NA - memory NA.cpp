bool compare(const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; }
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int n = intervals.size();
        int remove = 0;
        int lastMeet = 0;
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] < lastMeet) {
                remove++;
            } else {
                lastMeet = intervals[i][1];
            }
        }
        return remove;
    }
};