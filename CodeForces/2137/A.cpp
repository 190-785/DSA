#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k, x;
        cin >> k >> x;
        long long initial_value = x * (1LL << k);
        cout << initial_value << endl;
    }
    return 0;
}