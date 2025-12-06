class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int maxOdd = INT_MIN;
        int minEven = INT_MAX;
        
        for (int count : freq) {
            if (count % 2 == 0 && count > 0) {
                minEven = min(minEven, count);
            } else if (count % 2 != 0) {
                maxOdd = max(maxOdd, count);
            }
        }
        
        return maxOdd - minEven;
    }
};
