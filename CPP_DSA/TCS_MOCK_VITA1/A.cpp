/*Problem Description
Leo is trying to move his sofa to different place in his house. The issue is that the house is filled with lot of household items already.

His home will be divided into cells of M rows and N columns like a matrix. The matrix is used to represent the house and the things in it. The current placement of sofa will be represented as "s" and place where the sofa is required will be represented as "S". "H" represents the presence of household items while "0" indicates empty spaces where the Sofa can be moved. The sofa will always occupy two cells and can either move vertically or horizontally. The sofa can be rotated, but the rotation can only occur within a 2*2 area of free cells that includes the sofa. The destination to where the sofa needs to be moved will always be free of household items.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@25f9407e:image1.png

Since sofa is heavy object, it must only be moved and not lifted. Help Leo to find the minimum possible steps required to move the sofa to the required place without altering the positions of other household items. Moving the sofa one cell as well as rotating the sofa are considered as one step.

Constraints
4 < M, N < 25

Input
First line contains two space separated integers representing M, N.

Next M lines contain N space separated characters being either "s", "S", "H" or "0" representing the house's matrix.

Output
Print a single integer representing minimum number of steps required to move the sofa to the required place. Print "Impossible" if it is impossible to move the sofa to the required place.

Time Limit (secs)
1

Examples
Example 1

Input

5 5
s s 0 0 0
0 H 0 0 H
0 H 0 H H
0 H 0 0 H
0 0 0 S S

Output

8

Explanation

The diagram shown in the description depicts the input given

Below diagrams show the movement of sofa to the required place.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@25f9407e:image2.png

After two moves, the sofa occupies a 2x2 area of free cells, allowing it to be rotated. Following this process, the sofa has been moved to its destination in 8 steps, which represents the minimum required.

Example 2

Input

5 5
s s 0 H 0
0 H 0 0 H
0 H 0 H H
0 H 0 0 H
0 0 0 S S

Output

Impossible

Explanation

As you can see it impossible to move the sofa to the required place without rotating and there is not enough place to rotate the sofa, hence print "Impossible". */

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

using State = tuple<int, int, int, int>;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<vector<char>> grid(M, vector<char>(N));
    vector<pair<int, int>> start;
    vector<pair<int, int>> end;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 's')
            {
                start.push_back({i, j});
                grid[i][j] = '0';
            }
            if (grid[i][j] == 'S')
            {
                end.push_back({i, j});
                grid[i][j] = '0';
            }
        }
    }

    int startR = min(start[0].first, start[1].first);
    int startC = min(start[0].second, start[1].second);
    int startOrientation = (start[0].first == start[1].first) ? 0 : 1;

    int endR = min(end[0].first, end[1].first);
    int endC = min(end[0].second, end[1].second);
    int endOrientation = (end[0].first == end[1].first) ? 0 : 1;

    queue<State> q;
    q.push({startR, startC, startOrientation, 0});

    vector<vector<vector<bool>>> visited(M, vector<vector<bool>>(N, vector<bool>(2, false)));
    visited[startR][startC][startOrientation] = true;

    while (!q.empty())
    {
        auto [r, c, orientation, steps] = q.front();
        q.pop();

        if (r == endR && c == endC && orientation == endOrientation)
        {
            cout << steps << endl;
            return 0;
        }

        if (orientation == 0)
        {
            if (r + 1 < M && grid[r + 1][c] != 'H' && grid[r + 1][c + 1] != 'H' && !visited[r + 1][c][0])
            {
                q.push({r + 1, c, 0, steps + 1});
                visited[r + 1][c][0] = true;
            }
            if (r - 1 >= 0 && grid[r - 1][c] != 'H' && grid[r - 1][c + 1] != 'H' && !visited[r - 1][c][0])
            {
                q.push({r - 1, c, 0, steps + 1});
                visited[r - 1][c][0] = true;
            }
            if (c + 2 < N && grid[r][c + 2] != 'H' && !visited[r][c + 1][0])
            {
                q.push({r, c + 1, 0, steps + 1});
                visited[r][c + 1][0] = true;
            }
            if (c - 1 >= 0 && grid[r][c - 1] != 'H' && !visited[r][c - 1][0])
            {
                q.push({r, c - 1, 0, steps + 1});
                visited[r][c - 1][0] = true;
            }
        }
        else
        {
            if (r + 2 < M && grid[r + 2][c] != 'H' && !visited[r + 1][c][1])
            {
                q.push({r + 1, c, 1, steps + 1});
                visited[r + 1][c][1] = true;
            }
            if (r - 1 >= 0 && grid[r - 1][c] != 'H' && !visited[r - 1][c][1])
            {
                q.push({r - 1, c, 1, steps + 1});
                visited[r - 1][c][1] = true;
            }
            if (c + 1 < N && grid[r][c + 1] != 'H' && grid[r + 1][c + 1] != 'H' && !visited[r][c + 1][1])
            {
                q.push({r, c + 1, 1, steps + 1});
                visited[r][c + 1][1] = true;
            }
            if (c - 1 >= 0 && grid[r][c - 1] != 'H' && grid[r + 1][c - 1] != 'H' && !visited[r][c - 1][1])
            {
                q.push({r, c - 1, 1, steps + 1});
                visited[r][c - 1][1] = true;
            }
        }

        if (orientation == 0)
        {
            if (r + 1 < M && grid[r + 1][c] != 'H' && grid[r + 1][c + 1] != 'H')
            {
                if (!visited[r][c][1])
                {
                    q.push({r, c, 1, steps + 1});
                    visited[r][c][1] = true;
                }
                if (c + 1 < N && !visited[r][c + 1][1])
                {
                    q.push({r, c + 1, 1, steps + 1});
                    visited[r][c + 1][1] = true;
                }
            }
            if (r - 1 >= 0 && grid[r - 1][c] != 'H' && grid[r - 1][c + 1] != 'H')
            {
                if (!visited[r - 1][c][1])
                {
                    q.push({r - 1, c, 1, steps + 1});
                    visited[r - 1][c][1] = true;
                }
                if (c + 1 < N && !visited[r - 1][c + 1][1])
                {
                    q.push({r - 1, c + 1, 1, steps + 1});
                    visited[r - 1][c + 1][1] = true;
                }
            }
        }
        else
        {
            if (c + 1 < N && grid[r][c + 1] != 'H' && grid[r + 1][c + 1] != 'H')
            {
                if (!visited[r][c][0])
                {
                    q.push({r, c, 0, steps + 1});
                    visited[r][c][0] = true;
                }
                if (r + 1 < M && !visited[r + 1][c][0])
                {
                    q.push({r + 1, c, 0, steps + 1});
                    visited[r + 1][c][0] = true;
                }
            }
            if (c - 1 >= 0 && grid[r][c - 1] != 'H' && grid[r + 1][c - 1] != 'H')
            {
                if (!visited[r][c - 1][0])
                {
                    q.push({r, c - 1, 0, steps + 1});
                    visited[r][c - 1][0] = true;
                }
                if (r + 1 < M && !visited[r + 1][c - 1][0])
                {
                    q.push({r + 1, c - 1, 0, steps + 1});
                    visited[r + 1][c - 1][0] = true;
                }
            }
        }
    }

    cout << "Impossible" << endl;
    return 0;
}
