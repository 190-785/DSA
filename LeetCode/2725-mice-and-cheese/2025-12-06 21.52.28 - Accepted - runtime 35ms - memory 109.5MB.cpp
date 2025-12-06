class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        int res = 0, n = reward1.size();
        for(int i=0; i<n; i++){
            res += reward2[i];
            pq.push(reward1[i] - reward2[i]);
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};