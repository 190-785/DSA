class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int maxTrees = 0, i = 0;
        for (int j = 0; j < fruits.size(); j++) {
            count[fruits[j]]++;
            if (count.size() > 2) {
                count[fruits[i]]--;
                if (count[fruits[i]] == 0) {
                    count.erase(fruits[i]);
                }
                i++;
            }
            maxTrees = max(maxTrees, j - i + 1);
        }
        return maxTrees;
    }
};