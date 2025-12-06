class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i,temp;
        int n=nums.size();
        for(i=0;i<k%n;i++){
            temp=nums[n-1];
            for(int j=n-1;j>0;j--){
                nums[j%n]=nums[j-1];
            }
            nums[0]=temp;
        }
    }
};