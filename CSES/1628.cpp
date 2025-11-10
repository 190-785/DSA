#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateSubsetsSum(vector<long long> &arr, size_t idx, long long currentSum, vector<long long> &subsetSum)
{
    if (idx == arr.size())
    {
        subsetSum.push_back(currentSum);
        return;
    }
    generateSubsetsSum(arr, idx + 1, currentSum, subsetSum);
    generateSubsetsSum(arr, idx + 1, currentSum + arr[idx], subsetSum);
}

int main()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long> part1, part2;
    for (size_t i = 0; i < arr.size() / 2; i++)
    {
        part1.push_back(arr[i]);
    }
    for (size_t i = arr.size() / 2; i < arr.size(); i++)
    {
        part2.push_back(arr[i]);
    }
    vector<long long> subsetSum1, subsetSum2;
    generateSubsetsSum(part1, 0, 0, subsetSum1);
    generateSubsetsSum(part2, 0, 0, subsetSum2);
    sort(subsetSum1.begin(), subsetSum1.end());
    sort(subsetSum2.begin(), subsetSum2.end());
    long long cnt = 0;
    for (size_t i = 0; i < subsetSum1.size(); i++)
    {
        long long req = x - subsetSum1[i];
        cnt += upper_bound(subsetSum2.begin(), subsetSum2.end(), req) -
               lower_bound(subsetSum2.begin(), subsetSum2.end(), req);
    }
    cout << cnt << endl;
}