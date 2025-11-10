#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        set<long long> blackCells;
        for (int i = 0; i < m; ++i) {
            long long a;
            cin >> a;
            blackCells.insert(a);
        }

        map<long long, long long> intervals;
        long long lastPos = 0;
        for (long long blackPos : blackCells) {
            if (blackPos > lastPos + 1) {
                intervals[lastPos + 1] = blackPos - 1;
            }
            lastPos = blackPos;
        }
        if (lastPos < 3000000000LL) {
            intervals[lastPos + 1] = 3000000000LL;
        }

        for (int i = 0; i < n; ++i) {
            long long curPos = 1;
            for (int j = 0; j <= i; ++j) {
                if (s[j] == 'A') {
                    curPos++;
                } else {
                    auto it = intervals.upper_bound(curPos);
                    if (it == intervals.begin()) {
                        curPos = it->first;
                    } else {
                        auto prevIt = prev(it);
                        if (curPos < prevIt->second) {
                            curPos++;
                        } else {
                            curPos = it->first;
                        }
                    }
                }
            }
            
            long long landPos = curPos;
            if (blackCells.find(landPos) == blackCells.end()) {
                 blackCells.insert(landPos);
                 
                 auto it = intervals.upper_bound(landPos);
                 it--;
                 long long start = it->first;
                 long long end = it->second;
                 
                 intervals.erase(it);
                 if (landPos > start) {
                     intervals[start] = landPos - 1;
                 }
                 if (landPos < end) {
                     intervals[landPos + 1] = end;
                 }
            }
        }

        cout << blackCells.size() << "\n";
        bool first = true;
        for (long long cell : blackCells) {
            if (!first) {
                cout << " ";
            }
            cout << cell;
            first = false;
        }
        cout << "\n";
    }
    return 0;
}