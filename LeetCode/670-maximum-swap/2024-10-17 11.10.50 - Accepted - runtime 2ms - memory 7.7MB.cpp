class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int last[10] = {0};
        for (int i = 0; i < str.size(); ++i) {
            last[str[i] - '0'] = i;
        }
        for (int i = 0; i < str.size(); ++i) {
            for (int d = 9; d > str[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(str[i], str[last[d]]);
                    return stoi(str);
                }
            }
        }

        return num;
    }
};
