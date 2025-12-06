class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int area = 0;
            if (height[left] <= height[right]) {
                area = height[left] * (right - left);
                left++;
            } else {
                area = height[right] * (right - left);
                right--;
            }
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};