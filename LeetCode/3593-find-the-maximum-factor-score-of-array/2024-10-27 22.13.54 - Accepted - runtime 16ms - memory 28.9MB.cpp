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
        
        auto lcm = [](long long a, long long b) -> long long {
            return (a / gcd(a, b)) * b;
        };
        
        auto arrayLCM = [](const vector<int>& arr) -> long long {
            return accumulate(arr.begin(), arr.end(), 1LL, [](long long a, int b) {
                return (a / gcd(a, (long long)b)) * b;
            });
        };
        
        int originalGCD = arrayGCD(nums);
        long long originalLCM = arrayLCM(nums);
        
        long long maxScore = (long long)originalGCD * originalLCM;
        
        for (int i = 0; i < n; i++) {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            int currentGCD = arrayGCD(temp);
            long long currentLCM = arrayLCM(temp);
            maxScore = max(maxScore, (long long)currentGCD * currentLCM);
        }
        
        return maxScore;
    }
};