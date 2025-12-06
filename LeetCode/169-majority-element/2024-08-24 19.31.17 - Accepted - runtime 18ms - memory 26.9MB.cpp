class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int element=nums[0];
       int count=0;
       for(int i=0;i<nums.size();i++){
        int currel=nums[i];
        if(currel==element){
            count++;
        }
        else{
            if(count==0){
                count++;
                element=currel;
            }
            else{
                count--;
            }
        }
        if(count>nums.size()-1){
            return element;
        }
       }
       return element;
    }
};
