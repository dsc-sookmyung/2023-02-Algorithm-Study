n, k = map(int, input().split())
# arr = [[]] * 12
arr = [[] for _ in range(12)]

for i in range(n):
    position, value = map(int, input().split())
    # arr.append((position, value))
    arr[position].append(value)
    arr[position].sort()

year = 1
while year <= k:
    team = [0] * 12    # 포지션 번호로 [0] 은 제외

    for num in range(1, 12):  # 팀 구성
        team[num] = max(arr[num], default=0)

    for i in range(1, 12):  # 감소
        team[i] = max(team[i] - 1, 0)
        arr[i][0] = max(arr[i][0] - 1, 0)

    for num in range(1, 12):  # 재구성
        team[num] = max(arr[num], default=0)

    year += 1

print(sum(team))
