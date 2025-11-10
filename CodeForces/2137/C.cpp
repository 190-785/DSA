#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        if (a % 2 == 0)
        {
            if (b % 2 != 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                long long sum1 = a + b;
                long long sum2 = a / 2 * b + 2;
                cout << max(sum1, sum2) << "\n";
            }
        }
        else
        {
            if (b % 2 != 0)
            {
                cout << a * b + 1 << "\n";
            }
            else
            {
                if (b % 4 != 0)
                {
                    cout << -1 << "\n";
                }
                else
                {
                    long long sum1 = a * (b / 2) + 2;
                    long long sum2 = 2 * a + b / 2;
                    cout << max(sum1, sum2) << "\n";
                }
            }
        }
    }
    return 0;
}