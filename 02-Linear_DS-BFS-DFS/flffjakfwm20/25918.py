import sys 
input = sys.stdin.readline

n = int(input())
s = list(input().strip())
stack = []
min_day = 0
result = 0

# 원하는 문자열을 만들려면 최소 며칠이 걸리는지
for i in s:
  if (i == '('):
    result += 1
  else:
    result -= 1
  if (abs(result) > min_day):
    min_day = abs(result)
if (result == 0):
  print(min_day)
else:
  print(-1)