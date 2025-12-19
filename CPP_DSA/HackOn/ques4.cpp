#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

long long sumOfDivisors(long long n) {
    long long sum = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

long long sumOfSumOfDivisors(long long C) {
    long long total = 0;
    for (long long i = 1; i <= C; i++) {
        total = (total + sumOfDivisors(i)) % MOD;
    }
    return total;
}

long long findMinimumCost(vector<int> P, int y, int X) {
    int n = P.size();
    unordered_map<int,int> remCount;
    for (int v : P) remCount[v % y]++;
    int oddRems = 0;
    for (auto &rc : remCount) if (rc.second % 2) oddRems++;
    if ((n % 2 == 0 && oddRems > 0) || (n % 2 == 1 && oddRems != 1)) return -1;
    unordered_map<int, vector<int>> groups;
    for (int v : P) groups[v % y].push_back(v);
    long long totalOps = 0;
    for (auto &kv : groups) {
        auto &vec = kv.second;
        sort(vec.begin(), vec.end());
        int m = vec.size();
        for (int i = 0; i + 1 < m; i += 2) {
            long long diff = (long long)vec[i+1] - vec[i];
            totalOps += diff / y;
        }
    }
    return totalOps * X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, y, X;
    cin >> n >> y >> X;
    
    vector<int> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    
    long long minCost = findMinimumCost(P, y, X);
    
    if (minCost == -1) {
        cout << -1 << endl;
        return 0;
    }
    
    long long result = sumOfSumOfDivisors(minCost);
    
    cout << minCost << endl;
    cout << result << endl;
    
    return 0;
}
