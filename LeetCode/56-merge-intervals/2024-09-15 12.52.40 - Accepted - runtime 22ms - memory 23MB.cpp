class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }
        vector<vector<int>> newArr;
        // a= intervals[i][0]
        // b= intervals[i][1]
        // c= intervals[i+1][0]
        // d=intervals[i+1][1]
        sort(intervals.begin(), intervals.end());
        int i = 0;
        newArr.push_back(intervals[0]);
        for (i = 1; i < intervals.size(); i++) {
            // since we have sorted so a will always be < c
            // since we know that a<b && a<c && c<d
            // hence a < d
            vector<int>& last = newArr.back();
            if (last[1] >= intervals[i][0]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                newArr.push_back(intervals[i]);
            }
        }
        return newArr;
    }
};