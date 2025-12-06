class Solution {
public:
    int rec(int idx, int amount, vector<int>& coins) {
        if(idx==0){
        if(amount%coins[0]==0) return amount/coins[0];
        return 1e9;
        }
        int notTake = 0+rec(idx - 1, amount, coins);
        int take = INT_MAX;
        if (coins[idx] <= amount) {
            take =1+ rec(idx, amount - coins[idx], coins);
        }
        return min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size()-1;
        int res= rec(n, amount, coins);
        if(res>=1e9) return -1;
        else return res;
    }
};