#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y, int dir, int N, const vector<string>& grid, const string& word, const vector<int>& dx, const vector<int>& dy) {
    int L = word.size();
    for (int k = 0; k < L; k++) {
        int nx = x + k * dx[dir];
        int ny = y + k * dy[dir];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
        if (grid[nx][ny] != word[k]) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    string word;
    cin >> word;

    vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};
    vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int d = 0; d < 8; d++) {
                if (check(i, j, d, N, grid, word, dx, dy)) {
                    count++;
                }
            }
        }
    }

    cout << count;
    return 0;
}
