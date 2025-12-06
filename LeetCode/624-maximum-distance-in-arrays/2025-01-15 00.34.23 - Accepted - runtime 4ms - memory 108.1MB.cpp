class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minNum = arrays[0][0];
        int maxNum = arrays[0].back();
        int maxDistance = 0;

        for (int i = 1; i < arrays.size(); i++) {
            maxDistance = max(maxDistance, abs(arrays[i].back() - minNum));
            maxDistance = max(maxDistance, abs(maxNum - arrays[i][0]));
            minNum = min(minNum, arrays[i][0]);
            maxNum = max(maxNum, arrays[i].back());
        }

        return maxDistance;
    }
};
