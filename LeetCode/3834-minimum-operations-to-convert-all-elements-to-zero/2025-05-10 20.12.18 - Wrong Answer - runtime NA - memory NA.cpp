class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        vector<int> st;
        for (int x : nums) {
            if (x == 0) {
                st.clear();
                continue;
            }
            while (!st.empty() && st.back() > x) {
                res++;
                st.pop_back();
            }
            if (!st.empty() && st.back() == x)
                continue;
            st.push_back(x);
        }
        res += st.size();
        return res;
    }
};
