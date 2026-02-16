class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> stk;
        stk.push(0);
        int i = 1;
        while (i < n) {
            //cout<<"1 ";
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
               // cout<<"2 ";
                answer[stk.top()] = i - stk.top() ;
                stk.pop();
            }
            stk.push(i);
            i++;
        }
        return answer;
    }
};