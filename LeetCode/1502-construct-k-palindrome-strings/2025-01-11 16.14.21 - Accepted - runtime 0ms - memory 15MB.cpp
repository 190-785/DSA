class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k) return false;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            int n=s[i]-'a';
            freq[n]++;
        }
        int OddCounts=0;
        for(auto it:freq){
            if(it%2!=0) OddCounts++;
        }
        if(OddCounts>k) return false;
        return true;
    }
};