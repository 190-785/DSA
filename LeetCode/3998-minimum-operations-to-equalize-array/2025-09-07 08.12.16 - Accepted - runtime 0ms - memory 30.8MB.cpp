class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        bool allEqual=true;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                allEqual=false;
            }
        }
        if(allEqual) return 0;
        int target=nums[0];
        for(int i=1;i<n;i++)target&=nums[i];

        int res=0;
        int curr=~0;
        for(int i=0;i<n;i++){
            curr&=nums[i];
            if(curr==target){
                if(i==n-1 || (curr & nums[i+1])!=target){
                res++;
                curr=~0;
                }
            }
        }
        return res;
    }
};