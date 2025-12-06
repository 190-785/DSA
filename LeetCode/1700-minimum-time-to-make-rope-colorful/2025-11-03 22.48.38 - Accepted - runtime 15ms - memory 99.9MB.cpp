class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int currSum = 0;
        int currMax = 0;
        int n=colors.size();
        if(n<2) return 0;
        for (int i = 1; i < n; i++) {
            if (colors[i] == colors[i - 1]) {
                currSum += neededTime[i - 1];
                currMax = max(currMax, neededTime[i - 1]);
            } else {
                currSum += neededTime[i - 1];
                currMax = max(currMax, neededTime[i - 1]);
                res += (currSum - currMax);
                currSum = 0;
                currMax = 0;
            }
        }
        if(colors[n-2]==colors[n-1]){
            currSum+=neededTime[n-1];
            currMax=max(currMax,neededTime[n-1]);
            res+=currSum-currMax;
        }
        return res;
    }
};