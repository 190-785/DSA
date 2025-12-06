class Solution {
public:
    double powed(double x, int n, double res){
        if(!n){
            return res;
        }
        if(n%2==1){
            res*=x;
        }
        return powed(x*x,n/2,res);
    }
    double myPow(double x, int n) {
        double res=1.0;
        long long num=n;
        if(n<0){
            num=-num;
            x=1.0/x;
        }
        return powed(x,num,res);
        
    }
};