import sys

n, k = map(int, input().split())
arr = [[]] * 1000001

for i in range(n):
    position, value = map(int, sys.stdin.readline().split())
    arr[position] = value
    arr.sort()
print(arr)

# year = 1
# team = [[]] * 12    # 포지션 번호로 [0] 은 제외
# while year <= k:
#     for i in range(1, 12):
#         team[i] = max(arr[i])
