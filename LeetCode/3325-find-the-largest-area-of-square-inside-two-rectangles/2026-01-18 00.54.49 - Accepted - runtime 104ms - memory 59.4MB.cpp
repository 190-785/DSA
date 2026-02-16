class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long width = min(topRight[i][0], topRight[j][0]) -
                                  max(bottomLeft[i][0], bottomLeft[j][0]);
                long long height = min(topRight[i][1], topRight[j][1]) -
                                   max(bottomLeft[i][1], bottomLeft[j][1]);

                res = max(res, min(width, height));
            }
        }

        return res * res;
    }
};