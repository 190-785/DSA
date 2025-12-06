class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int>freq;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==1){
                sum+=nums[i];
            }
            else if(freq[nums[i]]==2){
                sum-=nums[i];
            }
        }
        return sum;
        
    }
};