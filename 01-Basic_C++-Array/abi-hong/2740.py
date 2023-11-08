import sys 
input = sys.stdin.readline

#행 * 열
n, m = map(int, input().split())
matrix_a = []
for _ in range(n):
  matrix_a.append(list(map(int, input().split())))

m, k = map(int, input().split())
matrix_b = []
for _ in range(m):
  matrix_b.append(list(map(int, input().split())))

# 2차원 배열 선언
result = [[0 for _ in range(k)] for _ in range(n)]

for i in range(n):
  for j in range(k):
    for f in range(m):
      result[i][j] += matrix_a[i][f] * matrix_b[f][j]

for rows in result:
  for element in rows:
    print(element, end=' ')
  print()