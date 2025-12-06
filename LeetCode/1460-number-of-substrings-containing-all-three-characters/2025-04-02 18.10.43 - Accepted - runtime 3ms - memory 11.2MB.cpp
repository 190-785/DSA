class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3,-1);
        int n=s.size();
        int l=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
            cnt+=(1+min({last[0],last[1],last[2]}));
        }
        return cnt;
    }
};