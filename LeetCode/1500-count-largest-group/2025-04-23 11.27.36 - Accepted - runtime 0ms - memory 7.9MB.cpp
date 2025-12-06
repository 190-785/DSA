class Solution {
public:
    int countLargestGroup(int n) {
        int res = 0;
        vector<long long> freq(100, 0);
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            int temp = i;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            freq[sum]++;
        }
        int maxFreq = *max_element(freq.begin(), freq.end());
        int count = 0;
        for (int f : freq) {
            if (f == maxFreq)
                count++;
        }
        return count;
    }
};