class Solution {
public:
    set<int> st;
    int removeDuplicates(vector<int>& nums) {
        int i,j=0;
        for(i=1;i<nums.size();i++){
            if(nums[j]!=nums[i]){
                j++;
                nums[j]=nums[i];
            }
        }
        return j+1;
    }
    
};