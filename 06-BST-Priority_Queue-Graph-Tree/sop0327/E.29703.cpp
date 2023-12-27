// 오답

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
    int x, y, distance;
};

// 이동 가능한 방향: 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// BFS 함수
int bfs(vector<string> &grid, Point start, Point end)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Point> q;

    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty())
    {
        Point current = q.front();
        q.pop();

        if (current.x == end.x && current.y == end.y)
        {
            return current.distance;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != 'D')
            {
                visited[nx][ny] = true;
                q.push({nx, ny, current.distance + 1});
            }
        }
    }

    // 도착 지점에 도달할 수 없는 경우
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    Point start, F, H;

    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];

        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 'S')
            {
                start = {i, j, 0};
            }
            else if (grid[i][j] == 'F')
            {
                F = {i, j, 0};
            }
            else if (grid[i][j] == 'H')
            {
                H = {i, j, 0};
            }
        }
    }

    // 첫 번째 경로의 길이
    int path1 = bfs(grid, start, F);

    // F에서 H로 갈 수 없는 경우
    if (path1 == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    // 두 번째 경로의 길이
    int path2 = bfs(grid, F, H);

    // F에서 H로 갈 수 없는 경우
    if (path2 == -1)
    {
        cout << -1 << endl;
        return 0;
    }

    // 두 경로의 합 출력
    cout << path1 + path2 << endl;

    return 0;
}