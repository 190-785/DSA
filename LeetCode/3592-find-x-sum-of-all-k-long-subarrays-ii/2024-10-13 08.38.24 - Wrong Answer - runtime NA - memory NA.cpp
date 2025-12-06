class Solution {
public:
    long long calculateXSum(map<int, vector<int>, greater<int>>& sortedFreq, int x) {
        long long sum = 0;
        int count = 0;
        for (auto& [freq, nums] : sortedFreq) {
            for (int num : nums) {
                if (count < x) {
                    sum += static_cast<long long>(num) * freq;
                    count++;
                } else {
                    break;
                }
            }
            if (count >= x) break;
        }
        return sum;
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> result;
        int n = nums.size();
        unordered_map<int, int> freq;
        map<int, vector<int>, greater<int>> sortedFreq;

        for (int i = 0; i < k; ++i) {
            freq[nums[i]]++;
        }
        for (auto& [num, count] : freq) {
            sortedFreq[count].push_back(num);
        }

        result.push_back(calculateXSum(sortedFreq, x));

        for (int i = k; i < n; ++i) {
            int outNum = nums[i - k];
            int inNum = nums[i];

            if (--freq[outNum] == 0) {
                freq.erase(outNum);
            }

            freq[inNum]++;

            sortedFreq.clear();
            for (auto& [num, count] : freq) {
                sortedFreq[count].push_back(num);
            }

            result.push_back(calculateXSum(sortedFreq, x));
        }

        return result;
    }
};
