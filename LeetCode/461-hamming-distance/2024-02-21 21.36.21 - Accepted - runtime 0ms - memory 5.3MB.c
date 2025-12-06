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
    unsigned int count=0;
    while(N){
      count += N & 1;
        N >>= 1;
    }
    return count;
}