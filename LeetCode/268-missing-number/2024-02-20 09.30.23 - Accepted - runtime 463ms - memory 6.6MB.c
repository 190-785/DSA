int missingNumber(int* nums, int numsSize) {
    int i,j,key;
   for(i=0;i<numsSize;i++){
       key=nums[i];
       j=i-1;
       while(j>-1 && nums[j]>key){
           nums[j+1]=nums[j];
           j--;
       }
       nums[j+1]=key;
   }
   for(i=0;i<numsSize;i++){
       if(nums[i]!=i){
           return i;
       }
   }
    return i;
}