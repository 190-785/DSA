class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        set<int> st;
        auto max_it = max_element(maximumHeight.begin(), maximumHeight.end());
        if (*max_it < maximumHeight.size()) {
            return -1;
        }
        long long sum = 0;
        for (auto it : maximumHeight) {
            if (st.find(it) == st.end()) {
                st.insert(it);
                sum += it;
            } else {
                int temp = it;
                while (temp > 0) {
                    if (st.find(temp) == st.end()) {
                        st.insert(temp);
                        sum += temp;
                        break;
                    }
                    temp--;
                }
                if (temp <= 0) {
                    return -1;
                }
            }
        }
        return sum;
        
    }
};