#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        int shrink = n - m;
        int shrink_left = shrink / 2;
        int shrink_right = shrink - shrink_left;

        int l_prime = l + shrink_left;
        int r_prime = r - shrink_right;

        cout << l_prime << " " << r_prime << endl;
    }
    return 0;
}
