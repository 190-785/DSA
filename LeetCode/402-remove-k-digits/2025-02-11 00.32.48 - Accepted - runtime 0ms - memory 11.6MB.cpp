class Solution {
public:
    string removeKdigits(string num, int k) {
        // Essentially work in the descending order pop if next is less and then
        // push else only push
        if (num.size() == k)
            return "0";
        stack<char> stk;
        for (char c : num) {
            while (!stk.empty() && k > 0 && stk.top() > c) {
                stk.pop();
                k--;
            }
            if (!stk.empty() || c != '0') {
                stk.push(c);
            }
        }
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        // return res; why this wouldn't work?
        // Because lets say the numnber is 1000 and we gotta remove 1 digit, we
        // remove 1 and then since we didn't push any leading zeroes hence our
        // string would be empty
        return res.empty() ? "0" : res;
    }
};