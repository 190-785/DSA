class Solution {
public:
    int getArea(const vector<pair<int, int>>& points) {
        int minRow = INT_MAX, maxRow = INT_MIN;
        int minCol = INT_MAX, maxCol = INT_MIN;
        for (auto& [r, c] : points) {
            minRow = min(minRow, r);
            maxRow = max(maxRow, r);
            minCol = min(minCol, c);
            maxCol = max(maxCol, c);
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> ones;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
                if (grid[r][c] == 1)
                    ones.emplace_back(r, c);

        int n = ones.size(), minTotalArea = INT_MAX;
        for (int mask1 = 1; mask1 < (1 << n); ++mask1) {
            for (int mask2 = 1; mask2 < (1 << n); ++mask2) {
                if (mask1 & mask2)
                    continue;
                vector<pair<int, int>> group1, group2, group3;
                for (int i = 0; i < n; ++i) {
                    if (mask1 & (1 << i))
                        group1.push_back(ones[i]);
                    else if (mask2 & (1 << i))
                        group2.push_back(ones[i]);
                    else
                        group3.push_back(ones[i]);
                }
                if (group1.empty() || group2.empty() || group3.empty())
                    continue;
                int area = getArea(group1) + getArea(group2) + getArea(group3);
                minTotalArea = min(minTotalArea, area);
            }
        }
        return minTotalArea;
    }
};
