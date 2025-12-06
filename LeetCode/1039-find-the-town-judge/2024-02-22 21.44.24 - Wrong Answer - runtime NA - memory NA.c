int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int i,j,count;
    for(i=0;i<trustSize;i++){
        int key= trust[i][1];
        count=0;
        for(j=0;j<trustSize;j++){
            if(key==trust[j][0]){
                break;
            }
            else{
                count++;
            }
        }
        if(count==trustSize){
            return key;
        }
    }
    return -1;
    
}