class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxE=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(maxE<sum){
                    maxE=sum;
                }
            if(sum<0){
                sum=0;
                
            }
            
        }
        return maxE;
    }
};