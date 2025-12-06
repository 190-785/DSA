class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long total=n*(n-1)/2;
        int goodPairs=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            int key=nums[i]-i;
            goodPairs+=freq[key];
            freq[key]++;
        }
        return total-goodPairs;
    }
};