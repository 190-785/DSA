class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
        // This is just LCS Since by finding LCS we can essentially get the
        // ordered way
        //This is space Optimized version
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if(nums1[i-1]==nums2[j-1]){
                    curr[j]=curr[j-1]+1;
                }
                else{
                    curr[j]=max(curr[j-1],prev[j]);
                }
            }
            prev=curr;
        }
        return curr[m];
    }
};