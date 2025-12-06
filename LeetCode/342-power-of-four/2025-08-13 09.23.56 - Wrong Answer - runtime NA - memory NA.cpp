class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        int maxNum=pow(4,15);
        //Maximum power of 4 that an int cal hold is 4^15
        // Hence by trying to find a remainder of that value from n 
        // If we get a non zero value then it means that n is not a power of 4
        return !(maxNum%n);
    }
};