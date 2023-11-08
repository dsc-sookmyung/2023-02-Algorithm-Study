import sys 
input = sys.stdin.readline

n = int(input())

# 규칙은 찾았지만 별 찍는 방법에 대해 고민
for i in range(1, n+1):
  print('*'*i + ' '*(2*n - 2*i) + '*'*i)
for j in range(1, n):
  print('*'*(n-j) + ' '*(2*j) + '*'*(n-j))