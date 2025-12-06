class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        const int INF = numeric_limits<int>::max();
        const int NINF = numeric_limits<int>::min();
        int len = buildings.size();
        unordered_map<int, int> rowMin, rowMax, colMin, colMax;
        rowMin.reserve(len);
        rowMax.reserve(len);
        colMin.reserve(len);
        colMax.reserve(len);

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            if (!rowMin.count(x)) {
                rowMin[x] = INF;
                rowMax[x] = NINF;
            }
            if (!colMin.count(y)) {
                colMin[y] = INF;
                colMax[y] = NINF;
            }

            rowMin[x] = min(rowMin[x], y);
            rowMax[x] = max(rowMax[x], y);
            colMin[y] = min(colMin[y], x);
            colMax[y] = max(colMax[y], x);
        }
        int covered = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            bool hasLeft = (y > rowMin[x]);
            bool hasRight = (y < rowMax[x]);
            bool hasAbove = (x > colMin[y]);
            bool hasBelow = (x < colMax[y]);
            if (hasLeft && hasRight && hasAbove && hasBelow) {
                ++covered;
            }
        }
        return covered;
    }
};
