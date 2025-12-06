class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        //The maximum power of 3 value that integer can hold is 1162261467 ( 3^19 ) .
        int maxNum = pow(3, 19);
        return !(maxNum % n);
    }
};