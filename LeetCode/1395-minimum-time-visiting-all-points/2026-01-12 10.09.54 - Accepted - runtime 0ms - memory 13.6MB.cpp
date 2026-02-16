class Solution {
public:
    int minTimeToVisitNextPoint(int currX, int currY, int targetX,
                                int targetY) {
        int reqX = abs(currX - targetX);
        int reqY = abs(currY - targetY);
        int individualSteps = abs(reqX - reqY);
        int totalSteps =
            individualSteps + abs((individualSteps - max(reqX, reqY)));
        return totalSteps;
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxTime = 0;
        int currX = points[0][0];
        int currY = points[0][1];
        for (int i = 1; i < n; i++) {
            maxTime += minTimeToVisitNextPoint(currX, currY, points[i][0],
                                               points[i][1]);
            currX = points[i][0];
            currY = points[i][1];
        }
        return maxTime;
    }
};