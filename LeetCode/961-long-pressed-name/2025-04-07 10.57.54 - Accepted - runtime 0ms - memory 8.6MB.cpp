class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        if(name.size()>typed.size()) return false;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
            } else {
                if (i == 0) {
                    return false;
                }
                if (i > 0 && typed[j] != name[i - 1]) {
                    return false;
                }
            }
            j++;
        }
       // if(name[name.size()-1] !=typed[typed.size()-1]) return false;
        while(i<name.size()){
            if(typed[j-1] !=name[i]) return false;
        }
        while (j < typed.size()) {
            if (name[name.size() - 1] != typed[j]) {
                return false;
            }
            j++;
        }
        return true;
    }
};