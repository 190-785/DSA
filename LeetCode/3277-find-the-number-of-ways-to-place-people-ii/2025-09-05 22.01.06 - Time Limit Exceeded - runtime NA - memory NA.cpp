class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            vector<int>& pointA = points[i];
            for (int j = 0; j < n; j++) {
                vector<int>& pointB = points[j];
                if (i == j ||
                    !(pointA[0] <= pointB[0] && pointA[1] >= pointB[1])) {
                    continue;
                }

                if (n == 2) {
                    res++;
                    continue;
                }

                bool isInside = false;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;

                    vector<int>& pointTmp = points[k];
                    bool isXContained =
                        pointTmp[0] >= pointA[0] && pointTmp[0] <= pointB[0];
                    bool isYContained =
                        pointTmp[1] <= pointA[1] && pointTmp[1] >= pointB[1];

                    if (isXContained && isYContained) {
                        isInside = true;
                        break;
                    }
                }

                if (!isInside)
                    res++;
            }
        }
        return res;
    }
};
