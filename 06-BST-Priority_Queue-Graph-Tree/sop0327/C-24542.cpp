#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MOD = 1e9 + 7;

int bfs(int x, vector<bool> &visit, const vector<vector<int>> &graph)
{
    queue<int> q;
    q.push(x);
    visit[x] = true;
    int number = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur])
        {
            if (!visit[nxt])
            {
                q.push(nxt);
                visit[nxt] = true;
                number += 1;
            }
        }
    }

    return number;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visit(n + 1, false);
    long long ans = 1;

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int v = 1; v <= n; ++v)
    {
        if (!visit[v])
        {
            ans = (ans * bfs(v, visit, graph)) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}