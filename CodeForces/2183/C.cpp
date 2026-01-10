#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k;
        cin >> n >> m >> k;
        
        long long left = k - 1;
        long long right = n - k;
        
        long long res = 1;
        
        // Try going left first, then right
        for (long long l = 0; l <= left; l++)
        {
            long long costLeft = (l > 0) ? (2 * l) : 0;
            if (costLeft > m) break;
            
            long long remaining = m - costLeft;
            long long r = min(right, remaining / 2);
            
            res = max(res, 1 + l + r);
        }
        
        // Try going right first, then left
        for (long long r = 0; r <= right; r++)
        {
            long long costRight = (r > 0) ? (2 * r) : 0;
            if (costRight > m) break;
            
            long long remaining = m - costRight;
            long long l = min(left, remaining / 2);
            
            res = max(res, 1 + l + r);
        }
        
        cout << res << "\n";
    }
    return 0;
}
