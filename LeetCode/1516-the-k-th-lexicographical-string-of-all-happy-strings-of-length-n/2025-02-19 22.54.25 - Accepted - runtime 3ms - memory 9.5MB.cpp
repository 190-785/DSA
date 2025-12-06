class Solution {
public:
    string getHappyString(int n, int k) {
        stack<string> s;
        int idx = 0;
        s.push("");
        while (!s.empty()) {
            string curr = s.top();
            s.pop();
            if (curr.size() == n) {
                idx++;
                if (idx == k) {
                    return curr;
                }
                continue;
            }

            for (char c = 'c'; c >= 'a'; c--) {
                if (!curr.empty() && curr.back() == c)
                    continue;
                s.push(curr + c);
            }
        }
        return "";
    }
};
