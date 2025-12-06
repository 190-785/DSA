class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //Since the elements of the original array are present 2 times hence the xorsum should be 0
        int xorsum=derived[0];
        for(int i=1;i<derived.size();i++){
            xorsum^=derived[i];
        }
        return !xorsum;
    }
};