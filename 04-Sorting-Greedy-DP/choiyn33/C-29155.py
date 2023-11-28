import sys

n = int(sys.stdin.readline().strip())
# level[1]에는 풀어야 할 난이도 1 문제 수가 있다.
level = [0] + list(map(int, sys.stdin.readline().split()))
arr = [[] for _ in range(6)]   # arr[1]은 난이도 1의 문제들의 시간
result = 0

for i in range(n):
    input = list(map(int, sys.stdin.readline().split()))

    arr[input[0]].append(input[1])
    arr[input[0]].sort()

for i in range(1, 6):
    if level[i] > 1:
        num = level[i]      # 풀어야 할 문제 수

        result += arr[i][0]
        for k in range(1, num):
            result += (arr[i][k] - arr[i][k-1])     # 휴식 시간
            result += arr[i][k]     # 푸는 시간

    elif level[i] == 1:
        result += arr[i][0] + 60


print(result)
