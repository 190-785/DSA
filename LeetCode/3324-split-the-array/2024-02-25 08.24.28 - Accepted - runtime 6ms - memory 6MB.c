bool isPossibleToSplit(int* nums, int numsSize) {
    int i,j,size[numsSize];
    for(i=0;i<numsSize;i++){
        size[i]=0;
    }
    for(i=0;i<numsSize;i++){
        for(j=i;j<numsSize;j++){
            if(nums[i]==nums[j]){
                size[i]++;
            }
        
        }
        if(size[i]>2){
            return 0;
        }
    }
    return 1;
    
}