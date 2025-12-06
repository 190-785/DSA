class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        unordered_set<string> pointSet;
        for (const auto& point : points) {
            pointSet.insert(to_string(point[0]) + "," + to_string(point[1]));
        }

        int maxArea = -1;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 != x2 && y1 != y2) {
                    if (pointSet.count(to_string(x1) + "," + to_string(y2)) &&
                        pointSet.count(to_string(x2) + "," + to_string(y1))) {
                        int area = abs(x2 - x1) * abs(y2 - y1);
                        bool hasInnerOrBorderPoint = false;
                        for (const auto& point : points) {
                            if ((point[0] > min(x1, x2) &&
                                 point[0] < max(x1, x2) &&
                                 point[1] > min(y1, y2) &&
                                 point[1] < max(y1, y2)) ||
                                (point[0] == x1 && point[1] > min(y1, y2) &&
                                 point[1] < max(y1, y2)) ||
                                (point[0] == x2 && point[1] > min(y1, y2) &&
                                 point[1] < max(y1, y2)) ||
                                (point[1] == y1 && point[0] > min(x1, x2) &&
                                 point[0] < max(x1, x2)) ||
                                (point[1] == y2 && point[0] > min(x1, x2) &&
                                 point[0] < max(x1, x2))) {
                                hasInnerOrBorderPoint = true;
                                break;
                            }
                        }
                        if (!hasInnerOrBorderPoint) {
                            maxArea = max(maxArea, area);
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};
