import sys 
input = sys.stdin.readline

n, m = map(int, input().split())
rooms = []

for i in range(n):
  rooms.append(list(input().strip()))
result = 0

# dfs
dx = [-1, 1]
dy = [-1, 1]
def dfs(x, y):
  if (rooms[x][y] == '-'):
    rooms[x][y] = 1 # 해당 노드 방문처리
    for i in dy:
      ny = y + i
      if (ny > 0 and ny < m) and (rooms[x][ny] == '-'):
        dfs(x, ny)
  if (rooms[x][y] == '|'):
    rooms[x][y] = 1 # 해당 노드 방문처리
    for i in dx:
      nx = x + i
      if (nx > 0 and nx < n) and (rooms[nx][y] == '|'):
        dfs(nx, y)

for i in range(n):
  for j in range(m):
    if (rooms[i][j] == '-') or (rooms[i][j] == '|'):
      dfs(i, j)
      result += 1

# 구현
for i in range(n):
  a = ''
  for j in range(m):
    if (rooms[i][j] == '-'):
      if (a != rooms[i][j]):
        result += 1
    a = rooms[i][j]

for i in range(m):
  a = ''
  for j in range(n):
    if (rooms[j][i] == '|'):
      if (a != rooms[j][i]):
        result += 1
    a = rooms[j][i]

print(result)