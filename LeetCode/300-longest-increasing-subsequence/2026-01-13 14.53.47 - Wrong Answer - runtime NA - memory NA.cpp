class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n + 1, 1), curr(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums[i - 1] < nums[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(curr[j], prev[j-1]);
                }
            }
            for (int i = 0; i <= n; i++) {
                cout << prev[i];
            }
            cout << endl;
            prev = curr;
        }

        cout << endl;
        for (int i = 0; i <= n; i++) {
            cout << prev[i];
        }
        return prev[n];
    }
};