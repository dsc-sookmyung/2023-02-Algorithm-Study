import sys

n, k = map(int, input().split())
arr = [] * 1000001

for i in range(n):
    position, value = map(int, sys.stdin.readline().split())
    arr.append = ((position, value))

year = 1
while year <= k:
    team = [0] * 12    # 포지션 번호로 [0] 은 제외

    for i in range(1, 12):  # 팀 구성
        team[i] = max_value = max(
            (value for p, value in arr if p == i), default=0)

    for i in range(11):  # 감소
        team[i] = max(team[i] - 1, 0)

    for i in range(1, 12):  # 재구성
        team[i] = max_value = max(
            (value for p, value in arr if p == i), default=0)

    year += 1

print(sum(team))
