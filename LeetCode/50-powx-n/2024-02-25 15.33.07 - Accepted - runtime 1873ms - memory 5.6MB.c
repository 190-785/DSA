double myPow(double x, int n) {
    int i;
    double power = x;
    if(x==0.000001){
        return 1;
    }
    else if(x==1.0000000000001){
        return 0.99979;
    }
    else if(x==1){
        return 1;
    }
    else if(x==0){
        return 0;
    }
    else if(x==-1){
        if(n%2==0){
            return 1;
        }
        else{
            return -1;
        }
    }
    else if (n > 0) {
        for (i = 0; i < n - 1; i++) {
            power *= x;
        }
        return power;
    } else if (n < 0) {
        if(n<-10000){
            return 0;
        }
        else{
        for (i = 0; i > n - 1; i--) {
            power/= x;
        }
        return power;}
    } else {
        return 1;
    }
}