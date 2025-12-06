class Solution {
public:
    void generateSubsetSum(int idx, int count, long long currSum,
                           vector<vector<long long>>& subsetSum,
                           vector<int>& arr) {
        if (idx == arr.size()) {
            subsetSum[count].push_back(currSum);
            return;
        }
        generateSubsetSum(idx + 1, count + 1, currSum + arr[idx], subsetSum,
                          arr);
        generateSubsetSum(idx + 1, count, currSum, subsetSum, arr);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        int mid = n / 2;
        vector<int> part1(nums.begin(), nums.begin() + mid);
        vector<int> part2(nums.begin() + mid, nums.end());

        vector<vector<long long>> subsetSum1(mid + 1), subsetSum2(mid + 1);

        generateSubsetSum(0, 0, 0, subsetSum1, part1);
        generateSubsetSum(0, 0, 0, subsetSum2, part2);

        for (int k = 0; k <= mid; k++) {
            sort(subsetSum2[k].begin(), subsetSum2[k].end());
        }

        long long res = LLONG_MAX;

        for (int k = 0; k <= mid; k++) {
            for (long long s1 : subsetSum1[k]) {
                long long target = total / 2 - s1;
                auto& vec = subsetSum2[mid - k];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    long long sum = s1 + *it;
                    res = min(res, llabs(total - 2 * sum));
                }
                if (it != vec.begin()) {
                    long long sum = s1 + *prev(it);
                    res = min(res, llabs(total - 2 * sum));
                }
            }
        }

        return (int)res;
    }
};
