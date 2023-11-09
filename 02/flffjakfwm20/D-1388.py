import sys 
input = sys.stdin.readline

n, m = map(int, input().split())
rooms = []

for i in range(n):
  rooms.append(list(input().strip()))

result = 0
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