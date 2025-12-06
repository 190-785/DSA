class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int validSelections = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                bool leftValid = simulate(nums, i, -1);
                bool rightValid = simulate(nums, i, 1);
                if (leftValid) ++validSelections;
                if (rightValid) ++validSelections;
            }
        }

        return validSelections;
    }

private:
    bool simulate(vector<int> nums, int curr, int direction) {
        int n = nums.size();
        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += direction;
            } else if (nums[curr] > 0) {
                --nums[curr];
                direction = -direction;
                curr += direction;
            }
        }
        return allZero(nums);
    }

    bool allZero(const vector<int>& nums) {
        return all_of(nums.begin(), nums.end(), [](int x) { return x == 0; });
    }
};
