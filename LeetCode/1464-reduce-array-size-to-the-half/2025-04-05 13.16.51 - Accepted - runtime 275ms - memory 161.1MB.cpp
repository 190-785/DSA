class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        int sum = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < mpp.size(); i++) {
            pq.push(mpp[i]);
        }
        n /= 2;
        while (!pq.empty()) {
            res++;
            sum += pq.top();
            if (sum >= n)
                return res;
            pq.pop();
        }
        return res;
    }
};