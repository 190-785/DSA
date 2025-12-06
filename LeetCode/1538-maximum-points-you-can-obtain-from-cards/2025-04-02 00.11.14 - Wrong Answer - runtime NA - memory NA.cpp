class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = 0, right = cardPoints.size() - 1;
        int sum = 0, cnt = 0;
        while (cnt < k) {
            if (cardPoints[left] > cardPoints[right]) {
                sum += cardPoints[left];
                left++;
            } else {
                sum += cardPoints[right];
                right--;
            }
            cnt++;
        }
        return sum;
    }
};