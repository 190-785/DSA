class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool istwobit=false;
        for(int i=0;i<bits.size();i++){
            if(bits[i]){
                istwobit=true;
                i++;
            }
            else{
                istwobit=false;
            }
        }
        return !istwobit;
    }
};