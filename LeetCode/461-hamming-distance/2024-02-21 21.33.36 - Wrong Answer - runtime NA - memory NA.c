int hammingDistance(int x, int y) {
    // int count;
    // if(x>y){
    // while(1){
    //     if(x!=y){
    //         x>>1;
    //         count++;
    //     }
    //     else{
    //         return count;
    //     }
    // }}
    // else{
    //      while(1){
    //     if(x!=y){
    //         x>>1;
    //         count++;
    //     }
    //     else{
    //         return count;
    //     }
    // }

    // }
    int N=x^y;
    int count=0;
    while(N){
        N>>=1;
        count++;
    }
    return count-1;
}