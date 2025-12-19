/*26. Imagine you are given a board of cells, each containing a bubble of a specific colour (as
shown below). Neighbouring cells of the bubble are defined as adjacent cells (on either the
same row or column as the given cell) which have a common side with the given cell. For
example, the neighbouring cells for each of the cells A, B and C are highlighted in corresponding
colour in the picture below.
Your task is to perform a bubble explosion on the board. A bubble is defined by the following
rules:
• A bubble within any given cell is eligible to explode if it has the same colour as bubbles
in at least 2 neighbouring cells.
• All eligible bubbles and bubbles of the same colour in neighbouring cells are marked for
explosion.
• All marked bubbles explode at the same time. Exploded bubbles are removed from the
board, resulting in empty cells.
• After all exploded bubbles are removed, remaining bubbles in cells above the empty
cells drop down to fill all empty cells.
You are given an initial board of cells bubbles – a multidimensional array of integers
representing cells containing bubbles of various colours. Return the board state after a bubble
Designed by :- CEC GEU & GEHU
explosion. The output should be a multidimensional array of integers with the same size as
bubbles, but replacing all the empty cells (without bubbles) with 0.
NOTE: You are not expected to provide the most optimal solution, but solution with the time
complexity not worse than O(bubbles.length2. bubbles[0].length2) will fit within the execution
time limit.
For Example
Bubbles =
[ [3, 1, 2, 1],
[1, 1, 1, 4],
[3, 1, 2, 2],
[3, 3, 3, 4]]
The output should be
[[0, 0, 0, 0],
[0, 0, 0, 1],
[0, 0, 0, 4],
[3, 0, 2, 4]] */

#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inBounds(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int x, int y, int color, vector<vector<int>> &board,
         vector<pair<int, int>> &group, vector<vector<bool>> &visited, bool &eligible)
{
    int n = board.size(), m = board[0].size();
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int cx = curr.first, cy = curr.second;
        group.push_back({cx, cy});

        int same = 0;
        for (int k = 0; k < 4; k++)
        {
            int nx = cx + dx[k], ny = cy + dy[k];
            if (inBounds(nx, ny, n, m) && board[nx][ny] == color)
            {
                same++;
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        if (same >= 1)
            eligible = true;
    }
}

void applyShifts(vector<vector<int>> &board)
{
    int n = board.size(), m = board[0].size();
    for (int j = 0; j < m; j++)
    {
        int write = n - 1;
        int read = n - 1;
        while (read >= 0)
        {
            if (board[read][j] > 0)
            {
                if (read != write)
                    swap(board[read][j], board[write][j]);
                write--;
            }
            read--;
        }
        for (int i = write; i >= 0; i--)
        {
            board[i][j] = 0;
        }
    }
}

vector<vector<int>> bubbleExplosion(vector<vector<int>> board)
{
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && board[i][j] > 0)
            {
                vector<pair<int, int>> group;
                bool eligible = false;
                bfs(i, j, board[i][j], board, group, visited, eligible);
                if (eligible)
                {
                    for (auto &p : group)
                    {
                        board[p.first][p.second] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == -1)
                board[i][j] = 0;
        }
    }
    applyShifts(board);
    return board;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    auto result = bubbleExplosion(board);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
