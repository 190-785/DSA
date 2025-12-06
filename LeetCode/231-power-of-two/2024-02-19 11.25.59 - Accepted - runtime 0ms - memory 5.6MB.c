bool isPowerOfTwo(int n) {
    int i;
    for(i=0;i<=n/2;i++){
        if(pow(2,i)==n){
            return 1;
        }
        else if(pow(2,i)>n){
            return 0;
        }

    }
    return 0;
}