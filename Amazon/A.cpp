#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> oldPass(n);
    vector<string> newPass(n);
    for (int i = 0; i < n; i++)
    {
        cin >> oldPass[i];
        cin >> newPass[i];
    }
    vector<bool> res(n, false);
    for (int i = 0; i < n; i++)
    {
        int j = 0, k = 0;
        string currOld = oldPass[i];
        string currNew = newPass[i];
        int m = oldPass[i].size();
        int mm = newPass[i].size();
        while (j < m && k < mm)
        {
            if (currOld[j] == currNew[k] || currOld[j] == char(currNew[k] + 1))
            {
                // cout<<currOld[j]<<" "<<char(currNew[k] + 1)<<endl;
                j++, k++;
            }
            else
            {
                k++;
            }
        }
        cout << j << endl;
        if (j == m)
        {
            res[i] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (res[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}


