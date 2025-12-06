class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int partSize = part.size();
        for (char c : s) {
            stk.push(c);
            
            if (stk.size() >= partSize) {
                string temp;
                for (int i = 0; i < partSize; i++) {
                    temp = stk.top() + temp;
                    stk.pop();
                }
                
                if (temp != part) {
                    for (char tc : temp) {
                        stk.push(tc);
                    }
                }
            }
        }

        string res;
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }
};