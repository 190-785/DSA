#include <iostream>
#include <vector>
#include <string>
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
    for (size_t i = 0; i < (size_t)n; i++)
    {
        size_t j = 0, k = 0;
        string currOld = oldPass[i];
        string currNew = newPass[i];
        size_t m = oldPass[i].size();
        size_t mm = newPass[i].size();
        while (j < m && k < mm)
        {
            char nextChar = (currNew[k] == 'z') ? 'a' : currNew[k] + 1;
            
            if (currOld[j] == currNew[k] || currOld[j] == nextChar)
            {
                j++;
            }
            k++;
        }
        if (j == m)
        {
            res[i] = true;
        }
    }
    for (size_t i = 0; i < (size_t)n; i++)
    {
        if (res[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
