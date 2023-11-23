import sys 
input = sys.stdin.readline

n = int(input())
questions = list(map(int, input().split()))
solve = []
result = 0

for i in range(n):
  level, time = map(int, input().split())
  solve.append((level, time))

# 난이도 1부터 난이도 5까지 난이도가 같거나 증가하는 순서대로 문제를 풀 것
# 각 문제와 문제 사이에는 휴식 시간이 필요한데 
# 이는 만약 두 문제가 같은 난이도라면 두 문제를 푸는 데 걸리는 시간의 차이만큼 필요하고 난이도를 증가시키는 경우 60분의 시간이 필요
# 문제를 푸는 데 걸리는 시간은 푼 문제의 예상 시간 합과 문제 사이 휴식 시간의 합
solve.sort(key=lambda x: (x[0], x[1]))
for i in range(0, len(questions)):
  count = 0
  result += 60
  for j in range(n):
    if (count == questions[i]):
      break
    if (solve[j][0] == i + 1):
      if (count == 0):
        result += solve[j][1]
      else:
        if (solve[j][1] == solve[j-1][1]):
          result += solve[j][1]
        else:
          result += solve[j][1] + solve[j][1] - solve[j-1][1]
      count += 1

# 문제를 푸는 데 필요한 최소 시간
print(result - 60)