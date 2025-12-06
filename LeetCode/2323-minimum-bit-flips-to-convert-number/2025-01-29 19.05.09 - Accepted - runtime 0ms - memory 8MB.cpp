class Solution {
public:
    int minBitFlips(int start, int goal) {
        int N = start ^ goal;
        unsigned int count = 0;
        while (N) {
            count += N & 1;
            N >>= 1;
        }
        return count;
    }
};