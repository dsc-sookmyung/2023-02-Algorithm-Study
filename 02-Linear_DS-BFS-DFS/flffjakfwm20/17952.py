import sys 
input = sys.stdin.readline

n = int(input())
# 과제는 가장 최근에 나온 순서대로 한다. 또한 과제를 받으면 바로 시작한다.
# 과제를 하던 도중 새로운 과제가 나온다면, 하던 과제를 중단하고 새로운 과제를 진행한다.
# 새로운 과제가 끝났다면, 이전에 하던 과제를 이전에 하던 부분부터 이어서 한다. (성애는 기억력이 좋기 때문에 아무리 긴 시간이 지나도 본인이 하던 부분을 기억할 수 있다.)
stack = []
result = 0

for _ in range(n):
  work = list(map(int, input().split()))
  
  if (work[0] == 1):
    stack.append((work[1], work[2]))
  if (stack):
    score, time = stack.pop()
    time -= 1
    if (time == 0):
      result += score
    else:
      stack.append((score, time))

print(result)