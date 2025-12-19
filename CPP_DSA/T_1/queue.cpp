#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q1;
    q1.push(13);
    q1.push(31);
    cout << q1.back() << endl;
    cout << q1.front() << endl;
    q1.pop();
    cout << q1.front() << endl;
    if (q1.empty())
    {
        cout << "Is Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }
}