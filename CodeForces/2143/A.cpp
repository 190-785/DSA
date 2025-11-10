#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        bool isPossible = true;
        for (int k = n; k >= 1; --k) {
            int maxValIdx = -1;
            int maxVal = 0;
            for (int i = 0; i < n; ++i) {
                if (p[i] > maxVal) {
                    maxVal = p[i];
                }
            }

            if (maxVal != k) {
                isPossible = false;
                break;
            }
            
            int countMax = 0;
            for (int i = 0; i < n; ++i) {
                if (p[i] == k) {
                    maxValIdx = i;
                    countMax++;
                }
            }
            
            if (countMax != 1) {
                isPossible = false;
                break;
            }

            int bestJ = -1;
            int countValidJ = 0;

            for (int j = 0; j <= n - k; ++j) {
                bool coversMax = (maxValIdx >= j && maxValIdx < j + k);
                if (!coversMax) {
                    continue;
                }

                bool coversZero = false;
                for (int i = j; i < j + k; ++i) {
                    if (p[i] == 0) {
                        coversZero = true;
                        break;
                    }
                }

                if (!coversZero) {
                    countValidJ++;
                    bestJ = j;
                }
            }
            
            if (countValidJ != 1) {
                isPossible = false;
                break;
            }

            for (int i = 0; i < k; ++i) {
                p[bestJ + i]--;
            }
        }

        if (isPossible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}