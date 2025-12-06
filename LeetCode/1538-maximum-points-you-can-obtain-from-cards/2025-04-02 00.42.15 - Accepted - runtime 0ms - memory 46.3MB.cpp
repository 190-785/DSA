class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = k - 1, right = cardPoints.size() - 1;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int cnt = 0;
        int maxSum = sum;
        while (cnt < k) {
            sum -= cardPoints[left];
            left--;
            sum += cardPoints[right];
            right--;
            maxSum = max(maxSum, sum);
            cnt++;
        }
        return maxSum;
    }
};