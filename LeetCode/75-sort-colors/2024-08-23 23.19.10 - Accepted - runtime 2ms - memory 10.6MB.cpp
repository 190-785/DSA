class Solution {
public:
    void sortColors(vector<int>& nums) {
        multiset<int> st;
        int n=nums.size()-1;
        for(int i=0;i<=n;i++){
            st.insert(nums[i]);
        }
        
        int count=0;
            for(int j=2;j>=0;j--){
               count=st.count(j);
                while(count){
                    nums[n]=j;
                    count--;
                    n--;
                }
            }
    }
};     