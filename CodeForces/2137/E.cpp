#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        long long k;
        cin >> n >> k;

        set<long long> distinctElements;
        long long initialSum = 0;
        for (int i = 0; i < n; i++) {
            long long val;
            cin >> val;
            distinctElements.insert(val);
            initialSum += val;
        }

        long long mex = 0;
        while (distinctElements.count(mex)) {
            mex++;
        }

        if (mex == n) {
            cout << initialSum << endl;
            continue;
        }

        if (k == 0) {
            cout << initialSum << endl;
            continue;
        }

        long long sumAfterOneOp = n * mex;

        if (k == 1) {
            cout << sumAfterOneOp << endl;
            continue;
        }

        long long valAfterTwoOps = (mex > 0) ? 0 : 1;
        long long sumAfterTwoOps = n * valAfterTwoOps;

        long long valAfterThreeOps = 1 - valAfterTwoOps;
        long long sumAfterThreeOps = n * valAfterThreeOps;
        
        if (k % 2 == 0) {
            cout << sumAfterTwoOps << endl;
        } else {
            cout << sumAfterThreeOps << endl;
        }
    }
    return 0;
}