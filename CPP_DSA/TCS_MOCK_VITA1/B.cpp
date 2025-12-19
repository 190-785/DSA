#include <bits/stdc++.h>
using namespace std;

int main()
{
    int initialBalance;
    cin >> initialBalance;
    int numOperations;
    cin >> numOperations;
    int currentBalance = initialBalance;
    vector<int> transactions;
    vector<pair<int, int>> commitHistory;
    int lastCommitSize = 0;

    for (int i = 0; i < numOperations; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "read")
        {
            cout << currentBalance << endl;
        }
        else if (operation == "credit")
        {
            int amount;
            cin >> amount;
            currentBalance += amount;
            transactions.push_back(amount);
        }
        else if (operation == "debit")
        {
            int amount;
            cin >> amount;
            currentBalance -= amount;
            transactions.push_back(-amount);
        }
        else if (operation == "abort")
        {
            int transNum;
            cin >> transNum;
            if (transNum >= 1 && transNum <= (int)transactions.size())
            {
                if (transNum > lastCommitSize)
                {
                    int val = transactions[transNum - 1];
                    if (val != 0)
                    {
                        currentBalance -= val;
                        transactions[transNum - 1] = 0;
                    }
                }
            }
        }
        else if (operation == "commit")
        {
            commitHistory.push_back({currentBalance, (int)transactions.size()});
            lastCommitSize = transactions.size();
        }
        else if (operation == "rollback")
        {
            int commitNum;
            cin >> commitNum;
            if (commitNum >= 1 && commitNum <= (int)commitHistory.size())
            {
                currentBalance = commitHistory[commitNum - 1].first;
                int committedAt = commitHistory[commitNum - 1].second;
                for (int idx = committedAt; idx < (int)transactions.size(); idx++)
                    transactions[idx] = 0;
                commitHistory.resize(commitNum);
                lastCommitSize = committedAt;
            }
        }
    }
    return 0;
}
