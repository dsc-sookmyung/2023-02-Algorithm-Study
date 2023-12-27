import sys
import collections


def bfs(x, visit, graph):
    q = collections.deque([x])
    visit[x] = True
    number = 1

    while q:
        cur = q.popleft()
        for nxt in graph[cur]:
            if visit[nxt]:
                continue
            q.append(nxt)
            visit[nxt] = True
            number += 1

    return number


graph = collections.defaultdict(list)
N, M = map(int, sys.stdin.readline().split())
visit = [False for _ in range(N+1)]
answer = 1
mod = 1000000007

for _ in range(M):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

for v in range(1, N+1):
    if not visit[v]:
        answer *= bfs(v, visit, graph)
        answer %= mod

print(answer)