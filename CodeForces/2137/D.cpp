#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            groups[val].push_back(i);
        }

        bool isPossible = true;
        for (auto const& [freq, idx] : groups) {
            if (idx.size() % freq != 0) {
                isPossible = false;
                break;
            }
        }

        if (!isPossible) {
            cout << -1 << endl;
        } else {
            vector<int> a(n);
            int cnt = 1;
            for (auto const& [freq, idx] : groups) {
                for (int i = 0; i < idx.size() / freq; i++) {
                    for (int j = 0; j < freq; j++) {
                        a[idx[i * freq + j]] = cnt;
                    }
                    cnt++;
                }
            }

            for (int i = 0; i < n; i++) {
                cout << a[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
        }
    }
    return 0;
}