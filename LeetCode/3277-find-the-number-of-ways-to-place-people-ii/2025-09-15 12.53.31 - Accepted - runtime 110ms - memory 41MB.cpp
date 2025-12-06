class Solution {
public:
    bool static sortarr(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        return b[1] < a[1];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int c = 0;
        int n = points.size();
        sort(points.begin(), points.end(), sortarr);
        for (int i = 0; i < n - 1; i++) {
            int a = points[i][1];
            int x = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int y = points[j][1];
                if (a >= y && y > x) {
                    c++;
                    x = y;
                }
            }
        }

        return c;
    }
};