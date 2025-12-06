class Solution {
public:
    int minElement(vector<int>& nums) {
        int min=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int temp=nums[i];
            while(temp!=0){
                sum+=temp%10;
                temp=temp/10;
            }
            if(sum<min){
                min=sum;
            }

        }
        return min;
    }
};