class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        int leftCount = 0, rightCount = 0, leftSum = 0, rightSum = 0;
        for (int i = 0; i < n; ++i) {
            if (boxes[i] == '1') {
                rightSum += i;
                rightCount++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                leftSum += leftCount;
                rightSum -= rightCount;
            }
            answer[i] = leftSum + rightSum;

            if (boxes[i] == '1') {
                leftCount++;
                rightCount--;
            }
        }

        return answer;
    }
};
