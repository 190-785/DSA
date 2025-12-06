class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long num=n;
        if(num<0){
            num=-num;
            x=1.0/x;
        }
        while(num){
            if(num%2==1){
                ans*=x;
                num--;
            }
            x*=x;
            num/=2;
        }
        return ans;
    }
};