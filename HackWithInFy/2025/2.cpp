#include <bits/stdc++.h>
using namespace std;

int findMax(const vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> freq;
    int maxSum = 0;
    int left = 0, SLeft = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (freq.find(arr[i]) == freq.end())
        {
            freq[arr[i]] = 1;
        }
        else
        {
            freq[arr[i]]++;
            // maxSum=max(maxSum,currSum);
        }

        while (freq.size() > k)
        {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0)
                freq.erase(arr[left]);
            left++;
        }

        int currWin = 0, maxWin = 0;
        for (int j = i; j >= left; j--)
        {

            currWin += arr[j];
            // cout<<"Left"<<left<<" "<<currWin<<endl;
            maxWin = max(maxWin, currWin);
        }
        maxSum = max(maxWin, maxSum);
    }
    return maxSum;
}
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMax(arr, k) << endl;
    return 0;
}