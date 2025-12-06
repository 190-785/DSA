class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        int n = target.size();
        int prev = target[0];
        for (int i = 1; i < n; i++) {
            if (prev < target[i])
                res += (target[i] - prev);
            prev = target[i];
        }
        return res;
    }
};