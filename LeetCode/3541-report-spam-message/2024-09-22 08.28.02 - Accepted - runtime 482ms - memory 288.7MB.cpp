class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count=0;

        unordered_set<string> st(bannedWords.begin(),bannedWords.end());
        unordered_set<string>::iterator it;
        for(const string& word : message){
            if(st.find(word)!=st.end()){
                count++;
                if(count==2){
                    return true;
                }
            }
        }
        return false;
    }
};