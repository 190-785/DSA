class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1==num2) return 1;
        int ops1 = num1 / num2;
        int ops2 = num2 / num1;
        if (num1 % num2 != 0)
            ops1++;
        if (num2 % num1 != 0)
            ops2++;
        return ops1+ops2;
    }
};