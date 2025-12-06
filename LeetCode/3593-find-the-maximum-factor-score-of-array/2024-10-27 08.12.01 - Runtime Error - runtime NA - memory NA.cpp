class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return (long long)nums[0] * nums[0];

        auto arrayGCD = [](const vector<int>& arr) -> int {
            return accumulate(arr.begin(), arr.end(), arr[0], gcd<int, int>);
        };

        auto lcm = [](int a, int b) -> int { return (a / gcd(a, b)) * b; };

        auto arrayLCM = [](const vector<int>& arr) -> int {
            return accumulate(arr.begin(), arr.end(), 1,
                              [](int a, int b) { return (a / gcd(a, b)) * b; });
        };

        int originalGCD = arrayGCD(nums);
        int originalLCM = arrayLCM(nums);

        long long maxScore = (long long)originalGCD * originalLCM;

        for (int i = 0; i < n; i++) {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            int currentGCD = arrayGCD(temp);
            int currentLCM = arrayLCM(temp);
            maxScore = max(maxScore, (long long)currentGCD * currentLCM);
        }

        return maxScore;
    }
};