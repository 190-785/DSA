class Solution {
public:
    double aboveAndBelowDiff(vector<vector<int>>& squares, double y) {
        double belowY = 0.0;
        double aboveY = 0.0;
        for (auto& square : squares) {
            double y0 = square[1];
            double L = square[2];
            double currBelowY = min(max(y - y0, 0.0), L);
            double currAboveY = L - currBelowY;

            belowY += currBelowY * L;
            aboveY += currAboveY * L;
        }
        return belowY - aboveY;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = 0;
        for (auto& sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)sq[1] + sq[2]);
        }
        double eps = 1e-6;
        while (high - low > eps) {
            double mid = low + (high - low) / 2;
            double diff = aboveAndBelowDiff(squares, mid);
            if (diff < 0)
                low = mid;
            else
                high = mid;
        }
        return (low + high) / 2;
    }
};
