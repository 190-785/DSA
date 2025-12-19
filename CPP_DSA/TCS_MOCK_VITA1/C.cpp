
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

bool isConnected(char band, int S, const vector<string> &grid, const vector<pair<int, int>> &coords)
{
    if (coords.empty())
    {
        return true;
    }
    vector<pair<int, int>> q;
    q.push_back(coords[0]);
    vector<vector<bool>> visited(S, vector<bool>(S, false));
    visited[coords[0].first][coords[0].second] = true;
    size_t head = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (head < q.size())
    {
        pair<int, int> curr = q[head++];
        int r = curr.first;
        int c = curr.second;

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < S && nc >= 0 && nc < S && grid[nr][nc] == band && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push_back({nr, nc});
            }
        }
    }
    return q.size() == coords.size();
}

bool isLoop(char band, int S, const vector<string> &grid)
{
    vector<string> tempGrid = grid;
    char otherBand = (band == '1' ? '2' : '1');

    for (int r = 1; r < S - 1; ++r)
    {
        for (int c = 1; c < S - 1; ++c)
        {
            if (tempGrid[r][c] == otherBand)
            {
                bool isVerticalOverlap = (tempGrid[r - 1][c] == band && tempGrid[r + 1][c] == band);
                bool isHorizontalOverlap = (tempGrid[r][c - 1] == band && tempGrid[r][c + 1] == band);
                if (isVerticalOverlap || isHorizontalOverlap)
                {
                    tempGrid[r][c] = band;
                }
            }
        }
    }

    vector<pair<int, int>> coords;
    for (int r = 0; r < S; ++r)
    {
        for (int c = 0; c < S; ++c)
        {
            if (tempGrid[r][c] == band)
            {
                coords.push_back({r, c});
            }
        }
    }

    if (coords.empty() || !isConnected(band, S, tempGrid, coords))
    {
        return false;
    }

    for (auto const &p : coords)
    {
        int r = p.first;
        int c = p.second;
        int neighborC = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < S && nc >= 0 && nc < S && tempGrid[nr][nc] == band)
            {
                neighborC++;
            }
        }
        if (neighborC != 2)
        {
            return false;
        }
    }
    return true;
}

bool isInside(int rP, int cP, char loopC, int S, const vector<string> &grid)
{
    int intersections = 0;
    for (int c = cP + 1; c < S; ++c)
    {
        if (grid[rP][c] == loopC)
        {
            if (rP > 0 && grid[rP - 1][c] == loopC)
            {
                intersections++;
            }
        }
    }
    return intersections % 2 == 1;
}

int main()
{   
    int S;
    cin >> S;
    vector<string> grid(S);
    vector<pair<int, int>> band1, band2;
    for (int i = 0; i < S; ++i)
    {
        cin >> grid[i];
        for (int j = 0; j < S; ++j)
        {
            if (grid[i][j] == '1')
                band1.push_back({i, j});
            if (grid[i][j] == '2')
                band2.push_back({i, j});
        }
    }

    int overlapCount = 0;
    bool overlapOneOnTwo = false;
    bool overlapTwoOnOne = false;

    for (int r = 1; r < S - 1; ++r)
    {
        for (int c = 1; c < S - 1; ++c)
        {
            if (grid[r][c] == '1')
            {
                if ((grid[r - 1][c] == '2' && grid[r + 1][c] == '2') ||
                    (grid[r][c - 1] == '2' && grid[r][c + 1] == '2'))
                {
                    overlapCount++;
                    overlapOneOnTwo = true;
                }
            }
            else if (grid[r][c] == '2')
            {
                if ((grid[r - 1][c] == '1' && grid[r + 1][c] == '1') ||
                    (grid[r][c - 1] == '1' && grid[r][c + 1] == '1'))
                {
                    overlapCount++;
                    overlapTwoOnOne = true;
                }
            }
        }
    }

    bool impossible = false;
    if (overlapOneOnTwo && overlapTwoOnOne)
    {
        if (isLoop('1', S, grid) && !band2.empty())
        {
            if (isInside(band2[0].first, band2[0].second, '1', S, grid))
            {
                impossible = true;
            }
        }
        if (!impossible && isLoop('2', S, grid) && !band1.empty())
        {
            if (isInside(band1[0].first, band1[0].second, '2', S, grid))
            {
                impossible = true;
            }
        }
    }

    if (impossible)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << overlapCount << endl;
    }

    return 0;
}