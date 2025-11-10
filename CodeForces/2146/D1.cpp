#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

void buildPermutation(vector<int>& nums, vector<int>& p, int l, int r) {
    if (nums.empty()) {
        return;
    }
    if (nums.size() == 1) {
        p[nums[0] - l] = nums[0];
        return;
    }

    sort(nums.begin(), nums.end());
    int msb = log2(nums.back() ^ nums.front());

    vector<int> groupZero, groupOne;
    for (int x : nums) {
        if ((x >> msb) & 1) {
            groupOne.push_back(x);
        } else {
            groupZero.push_back(x);
        }
    }

    if (groupZero.size() != groupOne.size()) {
        buildPermutation(groupZero, p, l, r);
        buildPermutation(groupOne, p, l, r);
    } else {
        vector<int> pZero(groupZero.size());
        vector<int> pOne(groupOne.size());
        
        vector<int> tempP(r + 1);
        
        buildPermutation(groupZero, tempP, l, r);
        for(size_t i = 0; i < groupZero.size(); ++i) pZero[i] = tempP[groupZero[i]];
        
        buildPermutation(groupOne, tempP, l, r);
        for(size_t i = 0; i < groupOne.size(); ++i) pOne[i] = tempP[groupOne[i]];

        for(size_t i = 0; i < groupZero.size(); ++i){
            p[groupZero[i] - l] = pOne[i];
            p[groupOne[i] - l] = pZero[i];
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;

        if (l == r) {
            cout << l << "\n";
            cout << l << "\n";
            continue;
        }
        
        int k = 0;
        while ((1 << (k + 1)) <= r) {
            k++;
        }
        long long mask = (1 << (k + 1)) - 1;
        
        if (l == 0 && r == mask) {
             cout << (long long)r * n << "\n";
             for (int i = 0; i < n; ++i) {
                cout << (i ^ r) << (i == n - 1 ? "" : " ");
             }
             cout << "\n";
             continue;
        }

        int bestK = 0;
        for (int bit = 17; bit >= 0; --bit) {
            long long countK = countSetBits(r, bit) - countSetBits(l - 1, bit);
            if (countK * 2 >= n) {
                bestK = bit;
                break;
            }
        }
        
        cout << (1LL << bestK) * n << "\n";
        
        vector<int> g0, g1;
        for(int i = l; i <= r; ++i){
            if((i >> bestK) & 1) g1.push_back(i);
            else g0.push_back(i);
        }

        vector<int> a(n);
        vector<bool> g1Used(g1.size(), false);
        vector<bool> g0Used(g0.size(), false);
        
        int p1 = 0;
        for(int i = 0; i < g0.size(); ++i){
            a[g0[i]-l] = g1[i];
            g1Used[i] = true;
        }

        int p0 = 0;
        for(int i = 0; i < g1.size(); ++i){
            if(!g1Used[i]){
                a[g1[i]-l] = g1[i];
            } else {
                a[g1[i]-l] = g0[p0++];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}