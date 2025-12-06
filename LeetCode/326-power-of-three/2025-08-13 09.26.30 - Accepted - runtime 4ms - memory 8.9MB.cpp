class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;
        // The maximum power of 3 value that integer can hold is 1162261467 (
        // 3^19 ) .
        //  Hence by trying to find a remainder of that value from n
        //  If we get a non zero value then it means that n is not a power of 3
        int maxNum = pow(3, 19);
        return !(maxNum % n);
    }
};