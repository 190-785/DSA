class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Using Floyd’s Tortoise and Hare 
        //Here we use slow and fast 'pointers' 
        //We essentially go to the indices of the element itself
        //Since only one element should point to eash index we find that duplicate one
        int slow=nums[0];
        int fast=nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};