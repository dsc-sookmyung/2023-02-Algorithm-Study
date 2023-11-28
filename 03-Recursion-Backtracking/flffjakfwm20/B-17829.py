import sys 
input = sys.stdin.readline

n = int(input())
matrix = []
for _ in range(n):
  matrix.append(list(map(int, input().split())))

def pooling(size, x, y):
  mid = size // 2
  if (size == 2):
    answer = [matrix[x][y], matrix[x][y+1], matrix[x+1][y], matrix[x+1][y+1]]
    answer.sort()
    return answer[-2]
  leftTop = pooling(mid, x, y)
  rightTop = pooling(mid, x, y+mid)
  leftBottom = pooling(mid, x+mid, y)
  rightBottom = pooling(mid, x+mid, y+mid)
  answer = [leftTop, rightTop, leftBottom, rightBottom]
  answer.sort()
  return answer[-2]

print(pooling(n, 0, 0))
