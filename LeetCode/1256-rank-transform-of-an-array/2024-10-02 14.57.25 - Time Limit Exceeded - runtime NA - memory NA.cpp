class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            auto it = st.find(arr[i]);
            if (it != st.end()) {
                int index = distance(st.begin(), it);
                arr[i] = index + 1;
            }
        }
        return arr;
    }
};