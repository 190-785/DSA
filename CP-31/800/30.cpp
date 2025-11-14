#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> roundNum;
    for (long long i = 1; i <= 999999; i++)
    {
        long long countOfDigits = 0;
        long long countOfZeroes = 0;
        long long temp = i;
        while (temp)
        {
            if (temp % 10 == 0)
                countOfZeroes++;
            countOfDigits++;
            temp /= 10;
        }
        if (countOfZeroes == countOfDigits - 1)
            roundNum.push_back(i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        long long res = 0;
        for (int i = 0; i < roundNum.size(); i++)
        {
            if (roundNum[i] <= n)
                res++;
            else
                break;
        }
        cout << res << endl;
    }
    return 0;
}
