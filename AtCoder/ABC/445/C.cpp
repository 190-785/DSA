#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> state(n, 0), res(n, -1);

    for (int i = 0; i < n; i++) {
        if (state[i] != 0) continue;

        int curr = i;
        vector<int> path;

        while (state[curr] == 0) {
            state[curr] = 1;
            path.push_back(curr);
            curr = a[curr];
        }

        if (state[curr] == 1) {
            vector<int> cycle;
            int node = curr;
            do {
                cycle.push_back(node);
                node = a[node];
            } while (node != curr);

            int cycleSize = cycle.size();
            for (int j = 0; j < cycleSize; j++) {
                res[cycle[j]] = cycle[j];
            }
        }

        for (int j = path.size() - 1; j >= 0; j--) {
            int node = path[j];
            if (res[node] == -1) {
                res[node] = res[a[node]];
            }
            state[node] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] + 1 << " ";
    }
    return 0;
}
