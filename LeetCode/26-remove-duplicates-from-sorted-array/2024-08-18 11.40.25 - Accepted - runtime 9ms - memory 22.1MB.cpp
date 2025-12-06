class Solution {
public:
    set<int> st;
    int removeDuplicates(vector<int>& nums) {
        int i;
        for(i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        i=0;
        for(auto it: st){
            nums[i]=it;
            i++;
        }
        return i;
    }
    
};