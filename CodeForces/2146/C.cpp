#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> stable;
        stable.push_back(0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                stable.push_back(i + 1);
            }
        }
        stable.push_back(n + 1);

        bool isFine = true;
        for (int i = 0; i < stable.size() - 1; ++i) {
            int len = stable[i+1] - stable[i] - 1;
            if (len == 1) {
                isFine = false;
                break;
            }
        }

        if (!isFine) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        vector<int> p(n + 1);
        
        int i = 1;
        while (i <= n) {
            if (s[i-1] == '1') {
                p[i] = i;
                i++;
            } else {
                int j = i;
                while (j <= n && s[j-1] == '0') {
                    j++;
                }
                int start = i;
                int end = j - 1;
                int k = end - start + 1;
                
                for (int l = 0; l < k - 1; l++) {
                    p[start + l] = start + l + 1;
                }
                p[end] = start;
                i = j;
            }
        }

        for (int k = 1; k <= n; ++k) {
            cout << p[k] << (k == n ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}