int hammingDistance(int x, int y) {
    int N=x^y;
    unsigned int count=0;
    while(N){
      count += N & 1;
        N >>= 1;
    }
    return count;
}