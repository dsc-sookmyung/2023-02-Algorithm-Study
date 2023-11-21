import sys 
input = sys.stdin.readline

n, m = map(int, input().split())
snow= [0] + list(map(int, input().split()))

def dfs(distance, size, time):
  global result
  if (time > m):
    return
  
  if (time <= m):
    result = max(result, size)

  if (distance <= n-1):
    dfs(distance+1, size + snow[distance+1], time+1)
  if (distance <= n-2):
    dfs(distance+2, size//2 + snow[distance+2], time+1)

result = -1
dfs(0, 1, 0)
print(result)