class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long current = 0, minVal = 0, maxVal = 0;
        
        for (int diff : differences) {
            current += diff;
            minVal = min(minVal, current);
            maxVal = max(maxVal, current);
        }
    
        long long range = maxVal - minVal;
        return max(0LL, (upper - lower + 1) - range);
    }
};
