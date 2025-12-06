class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int count=0;
        for(int i=0;i<message.size();i++){
            for(int j=0;j<bannedWords.size();j++){
                if(message[i]==bannedWords[j]){
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