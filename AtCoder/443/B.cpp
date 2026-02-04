#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    long long eaten = 0;
    int years = 0;
    while (eaten < K) {
        eaten += N + years;
        years++;
    }
    cout << years - 1 << endl;
    return 0;
}