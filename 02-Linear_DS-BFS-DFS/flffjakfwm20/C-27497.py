from collections import deque
import sys 
input = sys.stdin.readline

n = int(input())
complete_str = deque()
last_one = []

for _ in range(n):
  info = list(input().split())
  if (info[0] == '3'):
    if complete_str:
      if (last_one.pop() == 'front'):
        complete_str.popleft()
      else:
        complete_str.pop()
  elif (info[0] == '1'):
    complete_str.append(info[1])
    last_one.append('back')
  elif (info[0] == '2'):
    complete_str.appendleft(info[1])
    last_one.append('front')

if (list(complete_str)):
  print(''.join(list(complete_str)))
else:
  print(0)