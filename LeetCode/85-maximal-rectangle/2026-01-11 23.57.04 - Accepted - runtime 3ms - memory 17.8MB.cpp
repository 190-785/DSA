class Solution {
public:
    int maxAreaCurr(vector<int>& heights) {
        int n = heights.size();
        stack<int> monoStk;
        int maxArea = 0;
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        int maxArea = 0;
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = maxAreaCurr(heights);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};