from collections import deque
import sys 
input = sys.stdin.readline

n = int(input())
games = []
q = deque()

for i in range(n):
  games.append(list(input().strip()))

dx = [0, 0, 1, -1, 1, -1, 1]
dy = [1, -1, 0, 1, 1, -1, -1]

result = 0
def bfs(x, y):
  finished = False
  visited = [[0] * n for _ in range(n)]
  global result
  q.append((x, y))
  visited[x][y] = 1
  while q:
    x, y = q.popleft()
    for i in range(7):
      nx = x + dx[i]
      ny = y + dy[i]
      if (0 <= nx < n) and (0 <= ny < n):
        if (games[nx][ny] == '.') and (not visited[nx][ny]):
          q.append((nx, ny))
          visited[nx][ny] = 1
        if (games[nx][ny] == 'F'):
          result += 1
          finished = True
          break
      if finished:
        break

for i in range(n):
  for j in range(n):
    if (games[i][j] == '.'):
      bfs(i, j)

print(result)     