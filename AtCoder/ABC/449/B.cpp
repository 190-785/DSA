#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    int rows = H, cols = W;
    for (int i = 0; i < Q; i++) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            cout << x * cols << endl;
            rows -= x;
        } else {
            cout << rows * x << endl;
            cols -= x;
        }
    }
    return 0;
}