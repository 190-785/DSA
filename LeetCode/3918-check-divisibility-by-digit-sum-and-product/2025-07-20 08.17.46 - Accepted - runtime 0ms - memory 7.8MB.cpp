class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long prod = 1;
        int temp = n;
        while (temp) {
            sum += temp % 10;
            prod *= temp % 10;
            temp /= 10;
        }
        sum+=prod;
        if(n%sum==0)
            return true;
        return false;
    }
};