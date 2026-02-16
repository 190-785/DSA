class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> monoStk;
        for (int i = 0; i <= n; i++) {
            while (!monoStk.empty() &&
                   (i == n || heights[monoStk.top()] >= heights[i])) {
                int height = heights[monoStk.top()];
                monoStk.pop();
                int width;
                if (monoStk.empty())
                    width = i;
                else
                    width = i - monoStk.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            monoStk.push(i);
        }
        return maxArea;
    }
};