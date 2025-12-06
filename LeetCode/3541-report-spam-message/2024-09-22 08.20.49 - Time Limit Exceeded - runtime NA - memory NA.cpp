class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count=0;

        unordered_set<string> st;
        unordered_set<string>::iterator it;
        for(int i=0;i<bannedWords.size();i++){
            st.insert(bannedWords[i]);
        }
        for(int i=0;i<message.size();i++){
            for(it= st.begin(); it!=st.end();it++){
                if(message[i]==*it){
                    count++;
                    if(count==2){
                        return true;
                    }
                }
            }
            
        }
        return false;
    }
};