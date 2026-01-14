#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.length();
    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    int res=0;
    for(int f:freq){
        res=__gcd(res,f);
    }
    cout<<res<<endl;
    // int minFreq = n;
    // for (int f : freq)
    //     if (f > 0)
    //         minFreq = min(minFreq, f);

    // vector<int> candidates;
    
    // for (int i = 1; i * i <= minFreq; i++)
    // {
    //     if (minFreq % i == 0)
    //     {
    //         candidates.push_back(i);
    //         if (i != minFreq / i)
    //             candidates.push_back(minFreq / i);
    //     }
    // }

    // sort(candidates.begin(), candidates.end());

    // int low = 0;
    // int high = candidates.size() - 1;

    // while (low < high)
    // {
    //     int mid = low + (high - low + 1) / 2;
    //     bool isPossibleFlag = true;

    //     for (int f : freq)
    //     {
    //         if (f > 0 && f % candidates[mid] != 0)
    //         {
    //             isPossibleFlag = false;
    //             break;
    //         }
    //     }

    //     if (isPossibleFlag)
    //         low = mid;
    //     else
    //         high = mid - 1;
    // }

    // cout << candidates[low] << endl;
    return 0;
}
