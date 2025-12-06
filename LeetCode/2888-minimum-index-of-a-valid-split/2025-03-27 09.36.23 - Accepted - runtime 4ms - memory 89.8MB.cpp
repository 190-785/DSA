class Solution {
public:
    int dominent(vector<int>& nums) {
        int element = nums[0];
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currEl = nums[i];
            if (currEl == element) {
                count++;
            } else {
                if (count == 0) {
                    element = currEl;
                    count++;
                } else {
                    count--;
                }
            }
        }
        cout << element;
        return element;
    }

    int minimumIndex(vector<int>& nums) {
        int domEl = dominent(nums);
        int n = nums.size();
        int dom = -1;
        int countD = 0;
        int i = 0;
        for (i; i < n; i++) {
            if (dom == -1) {
                if (nums[i] == domEl) {
                    countD++;
                    if (countD > (i + 1) / 2) {
                        dom = i;
                        countD = 0;
                    }
                }
            } else {
                if (nums[i] == domEl) {
                    countD++;
                }
            }
        }
        if (countD <= (n - dom - 1) / 2) {
            return -1;
        } else {
            return dom;
        }
    }
};