#include <bits/stdc++.h>
using namespace std;
long long sqrtFloor(long long n)
{
    if (n <= 0)
        return 0;
    long double d = sqrt((long double)n);
    long long r = (long long)floor(d);
    while ((r + 1) * (long double)(r + 1) <= n)
        ++r;
    while (r * (long double)r > n)
        --r;
    return r;
}

bool existsFeasibleKAtMost(long long maxKToCheck, long long x, long long y, long long S)
{
    if (maxKToCheck <= 0)
        return false;
    if (maxKToCheck >= 1)
    {
        if (y == 0 && x >= 1)
            return true;
    }
    long long sqrt1Plus8S = sqrtFloor(1 + 8 * S);
    long long sqrt1Plus4Y = sqrtFloor(1 + 4 * y);
    long long sqrtX = sqrtFloor(x);

    long long maxTForEven = maxKToCheck / 2;
    if (maxTForEven >= 1)
    {
        long long maxTFromXSquare = sqrtX;
        long long maxTFromYProduct = (sqrt1Plus4Y - 1) / 2;
        long long maxTFromTotalSum = (sqrt1Plus8S - 1) / 4;
        long long maxTFromDifferenceYX = y - x;
        long long tMax = min({maxTFromXSquare, maxTFromYProduct, maxTFromTotalSum,
                              maxTFromDifferenceYX, maxTForEven});
        if (tMax >= 1)
            return true;
    }

    long long maxTForOdd = (maxKToCheck - 1) / 2;
    if (maxTForOdd >= 1)
    {
        long long maxTFromXPlusOneSquare = sqrtX - 1;
        long long maxTFromYProduct = (sqrt1Plus4Y - 1) / 2;
        long long maxTFromTotalSum = (sqrt1Plus8S - 3) / 4;
        long long maxTFromDifferenceXY = x - y - 1;
        long long tMax = min({maxTFromXPlusOneSquare, maxTFromYProduct, maxTFromTotalSum,
                              maxTFromDifferenceXY, maxTForOdd});
        if (tMax >= 1)
            return true;
    }

    return false;
}

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long S = x + y;
        long long kMax = (sqrtFloor(1 + 8 * S) - 1) / 2;
        if (kMax < 1)
        {
            cout << -1 << '\n';
            continue;
        }

        long long low = 1, high = kMax, res = -1;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            if (existsFeasibleKAtMost(mid, x, y, S))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
