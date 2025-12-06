class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitSum(n), org = nums;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int num = org[i];
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            digitSum[i] = sum;
        }
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({digitSum[i], org[i]});
        }
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        vector<int> sortedArr(n);
        for (int i = 0; i < n; i++) {
            sortedArr[i] = vec[i].second;
        }
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[org[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (org[i] != sortedArr[i]) {
                swaps++;
                int correctVal = sortedArr[i];
                int indexToSwap = pos[correctVal];
                int temp = org[i];
                swap(org[i], org[indexToSwap]);
                pos[temp] = indexToSwap;
                pos[correctVal] = i;
            }
        }
        return swaps;
    }
};
