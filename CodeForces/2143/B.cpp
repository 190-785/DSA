#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int k;
        cin >> n >> k;
        vector<long long> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }
        vector<int> vouchers(k);
        for (int i = 0; i < k; ++i) {
            cin >> vouchers[i];
        }

        sort(prices.begin(), prices.end(), greater<long long>());
        sort(vouchers.begin(), vouchers.end());

        long long totalCost = 0;
        int itemsUsed = 0;
        int voucherIdx = 0;

        while (voucherIdx < k) {
            int voucherSize = vouchers[voucherIdx];
            
            if (itemsUsed + voucherSize > n) {
                break;
            }

            for (int i = 0; i < voucherSize - 1; i++) {
                totalCost += prices[itemsUsed];
                itemsUsed++;
            }
            itemsUsed++; 
            voucherIdx++;
        }

        while (itemsUsed < n) {
            totalCost += prices[itemsUsed];
            itemsUsed++;
        }

        cout << totalCost << "\n";
    }
    return 0;
}