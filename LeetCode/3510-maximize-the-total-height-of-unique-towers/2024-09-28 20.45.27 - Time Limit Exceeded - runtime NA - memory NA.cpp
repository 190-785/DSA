class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        unordered_set<int> st;
        auto max_it = max_element(maximumHeight.begin(), maximumHeight.end());
        if (*max_it < maximumHeight.size()) {
            return -1;
        }
        long long sum = 0;
        for (int it : maximumHeight) {
            if (st.insert(it).second) {
                sum += it;
            } else {
                int temp = it;
                while (temp > 0 && !st.insert(temp).second) {
                    temp--;
                }
                if (temp <= 0) {
                    return -1;
                }
                sum += temp;
            }
        }
        return sum;
        
    }
};