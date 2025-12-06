class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> res;
        for (int i = 0; i < asteroids.size(); i++) {
            int b = asteroids[i];
            bool isAlive = true;

            while (isAlive && !stk.empty() && stk.top() > 0 && b < 0) {
                int a = stk.top();
                if (abs(a) == abs(b)) {
                    stk.pop();
                    isAlive = false;
                } else if (abs(a) > abs(b)) {
                    isAlive = false;
                } else {
                    stk.pop();
                }
            }

            if (isAlive) {
                stk.push(b);
            }
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};