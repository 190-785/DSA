double myPow(double x, int n) {
    int i;
    double power = x;
    if(x==1){
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
            return 0;
        }
    }
    else if (n > 0) {
        for (i = 0; i < n - 1; i++) {
            power *= x;
        }
        return power;
    } else if (n < 0) {
        for (i = 0; i > n - 1; i--) {
            power /= x;
        }
        return power;
    } else {
        return 1;
    }
}