import sys

n = int(sys.stdin.readline().strip())
arr = list(map(int, sys.stdin.readline().split()))

arr.sort()

result = 0
for i in range(1, n):
    result += arr[i] - arr[i-1]

result += arr[n-1] - arr[0]
print(result)
