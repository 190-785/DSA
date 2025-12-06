class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
            } else {
                if (i == 0)
                    return false;
                if (i > 0 && typed[j] != name[i - 1]) {
                    return false;
                }
            }
            j++;
        }
        while (j < typed.size()) {
            if (name[i - 1] != typed[j])
                return false;
        }
        return true;
    }
};