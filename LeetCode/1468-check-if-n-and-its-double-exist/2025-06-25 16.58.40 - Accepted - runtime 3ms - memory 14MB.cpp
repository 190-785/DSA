class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> visited;
        for (int num : arr) {
            if (visited.count(num * 2) ||
                ((num % 2 == 0) && visited.count(num / 2)))
                return true;
            visited.insert(num);
        }
        return false;
    }
};