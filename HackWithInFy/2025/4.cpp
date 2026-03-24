// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/
// This is the same ques

#include <bits/stdc++.h>
using namespace std;

int bfs(int n, unordered_set<int> &vis, queue<pair<int, int>> &q)
{
    // queue -> currNum,steps;
    vis.insert(n);
    q.push({n, 0});
    while (!q.empty())
    {
        int currNum = q.front().first, steps = q.front().second;
        q.pop();
        if (currNum == 1)
            return steps;
        if (currNum % 3 == 0)
        {
            // if (currNum / 3 == 1) {
            //     return steps + 1;
            // }
            if (!vis.count(currNum / 3))
            {
                vis.insert(currNum / 3);
                q.push({currNum / 3, steps + 1});
            }
        }
        if (currNum % 2 == 0)
        {
            // if (currNum / 2 == 1) {
            //     return steps + 1;
            // }
            if (!vis.count(currNum / 2))
            {
                vis.insert(currNum / 2);
                q.push({currNum / 2, steps + 1});
            }
        }
        // if (currNum == 1)
        //     return steps + 1;
        if (!vis.count(currNum - 1))
        {
            vis.insert(currNum - 1);
            q.push({currNum - 1, steps + 1});
        }
    }
    return -1;
}
int minDays(int n)
{
    if (n == 1)
        return 0;
    queue<pair<int, int>> q;
    unordered_set<int> vis;
    return bfs(n, vis, q);
}

int main()
{
    int n;
    cin >> n;
    cout << minDays(n) << endl;
    return 0;
}