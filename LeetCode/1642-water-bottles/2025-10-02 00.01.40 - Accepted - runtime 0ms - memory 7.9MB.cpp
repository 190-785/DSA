class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        while (numBottles >= numExchange) {
            int curr = numBottles / numExchange;
            res += numExchange * curr;
            numBottles -= numExchange * curr;
            numBottles += curr;
        }
        return res + numBottles;
    }
};