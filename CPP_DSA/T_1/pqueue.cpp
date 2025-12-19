#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq; // By default it is max heap

    // Internally works on the basis on bst { where if th elargest value is at root then max heap and vice versa}
    // smallest on top-> min heap
    // largest on top->max heap

    pq.push(1);
    pq.push(41);
    pq.push(2);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    // For min heap
    priority_queue<int, vector<int>, greater<int>> pq1;

    pq1.push(31);
    pq1.push(3); // TC-> O(LogN)
    pq1.push(54);
    cout << pq1.top() << endl;
    pq1.pop();                 // TC-> O(LogN)
    cout << pq1.top() << endl; // TC-> O(1)
}