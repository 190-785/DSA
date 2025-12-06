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
        if(n<0){
            n=-n;
            x=1.0/x;
        }
        return powed(x,n,res);
        
    }
};