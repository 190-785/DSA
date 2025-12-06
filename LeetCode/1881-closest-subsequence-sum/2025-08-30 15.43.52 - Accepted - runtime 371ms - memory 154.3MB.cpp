class Solution {
public:
    void generateSubsetSum(int idx, long long currentSum,
                           const vector<int>& arr,
                           vector<long long>& subsetSum) {
        if (idx == arr.size()) {
            subsetSum.push_back(currentSum);
            return;
        }
        generateSubsetSum(idx + 1, currentSum + arr[idx], arr, subsetSum);
        generateSubsetSum(idx + 1, currentSum, arr, subsetSum);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> arr1(nums.begin(), nums.begin() + n / 2);
        vector<int> arr2(nums.begin() + n / 2, nums.end());

        vector<long long> subsetSum1, subsetSum2;
        generateSubsetSum(0, 0, arr1, subsetSum1);
        generateSubsetSum(0, 0, arr2, subsetSum2);

        sort(subsetSum2.begin(), subsetSum2.end());

        long long res = LLONG_MAX;
        for (long long s1 : subsetSum1) {
            long long target = goal - s1;
            auto it = lower_bound(subsetSum2.begin(), subsetSum2.end(), target);

            if (it != subsetSum2.end())
                res = min(res, abs(s1 + *it - goal));
            if (it != subsetSum2.begin()) {
                --it;
                res = min(res, abs(s1 + *it - goal));
            }
            if (res == 0)
                return 0;
        }

        return (int)res;
    }
};
