class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> nums(n + 1, 0);
        vector<int> result(n, 0);
        int common = 0;

        for (int i = 0; i < n; i++) {
            if (nums[A[i]] == 0) {
                nums[A[i]] = 1;
            } else if (nums[A[i]] == 2) {
                nums[A[i]] = 3;
                common++;
            }

            if (nums[B[i]] == 0) {
                nums[B[i]] = 2;
            } else if (nums[B[i]] == 1) {
                nums[B[i]] = 3;
                common++;
            }

            result[i] = common;
        }

        return result;
    }
};
