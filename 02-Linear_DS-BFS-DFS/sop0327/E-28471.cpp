#include <iostream>
#include <vector>
#include <queue>
#include <tuple> // tuple 헤더 추가

using namespace std;

int dx[] = {0, 0, 1, -1, 1, -1, 1};
int dy[] = {1, -1, 0, 1, 1, -1, -1};

void bfs(int x, int y, int n, vector<vector<char>> &games, vector<vector<int>> &visited, int &result)
{
    bool finished = false;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty())
    {
        int nx, ny;
        tie(nx, ny) = q.front();
        q.pop();

        for (int i = 0; i < 7; ++i)
        {
            int nnx = nx + dx[i];
            int nny = ny + dy[i];

            if (nnx >= 0 && nnx < n && nny >= 0 && nny < n)
            {
                if (games[nnx][nny] == '.' && !visited[nnx][nny])
                {
                    q.push({nnx, nny});
                    visited[nnx][nny] = 1;
                }
                if (games[nnx][nny] == 'F')
                {
                    result++;
                    finished = true;
                    break;
                }
            }
        }

        if (finished)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<char>> games(n, vector<char>(n));
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> games[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (games[i][j] == '.')
            {
                bfs(i, j, n, games, visited, result);
            }
        }
    }

    cout << result << endl;

    return 0;
}