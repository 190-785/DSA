class Solution {
public:
    int subarrayBitwiseORs(vector<int>& a) {
        unordered_set<int> res;
        unordered_set<int> cur;

        for (int x : a) {
            unordered_set<int> next;
            next.insert(x);

            for (int y : cur) {
                next.insert(x | y);
            }

            res.insert(next.begin(), next.end());
            cur = move(next);
        }

        return res.size();
    }
};
