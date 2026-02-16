class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n), rightSmall(n);
        stack<int> monoStk;
        for (int i = 0; i < n; i++) {
            while (!monoStk.empty() && heights[i] <= heights[monoStk.top()])
                monoStk.pop();
            if (monoStk.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = monoStk.top() + 1;
            monoStk.push(i);
        }
        while (!monoStk.empty())
            monoStk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!monoStk.empty() && heights[monoStk.top()] >= heights[i]) {
                monoStk.pop();
            }
            if (monoStk.empty())
                rightSmall[i] = n - 1;
            else
                rightSmall[i] = monoStk.top() - 1;
            monoStk.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = (rightSmall[i] - leftSmall[i] + 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};