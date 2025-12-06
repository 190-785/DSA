class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        while (numExchange <= numBottles) {
            numBottles -= (numExchange - 1);
            res++;
            numExchange++;
        }
        return res;
    }
};