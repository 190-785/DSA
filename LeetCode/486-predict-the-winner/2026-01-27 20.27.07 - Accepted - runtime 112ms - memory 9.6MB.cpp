class Solution {
public:
    int choices(vector<int>&nums,int start,int end,int turn){
        if(start==end) return turn * nums[start];
        int startScore=turn*nums[start] + choices(nums,start+1,end,-turn);
        int endScore=turn*nums[end]+choices(nums,start,end-1,-turn);
        return turn*(max(turn*startScore,turn*endScore));
    }
    bool predictTheWinner(vector<int>& nums) {
        /*
            sp1>=sp2
            (sp1-sp2)>=0

        */
        int n=nums.size();
        return (choices(nums,0,n-1,1)>=0);
    }
};