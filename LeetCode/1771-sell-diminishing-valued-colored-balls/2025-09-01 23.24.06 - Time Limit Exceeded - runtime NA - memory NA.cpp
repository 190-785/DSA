class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int MOD = 1e9 + 7;
        priority_queue<int> pq(inventory.begin(), inventory.end());
        int res = 0;
        while (orders) {
            int maxVal = pq.top();
            pq.pop();
            res = (res + maxVal) % MOD;
            maxVal--;
            if (maxVal)
                pq.push(maxVal);
            orders--;
        }
        return res;
    }
};