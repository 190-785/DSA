class Solution {
private:
    vector<int> findNSE(vector<int>& arr, int n) {
        stack<int> stk;
        vector<int> nse(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                nse[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            nse[stk.top()] = n;
            stk.pop();
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr, int n) {
        stack<int> stk;
        vector<int> psee(n);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            psee[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        return psee;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr, n);
        vector<int> psee = findPSEE(arr, n);
        long long total = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};
