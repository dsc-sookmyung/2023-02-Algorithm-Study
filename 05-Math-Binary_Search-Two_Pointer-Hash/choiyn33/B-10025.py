import sys

n, k = map(int, sys.stdin.readline().rsplit())
ice = [0] * 1000001

for i in range(n):
    input = list(map(int, sys.stdin.readline().split()))
    amt = int(input[0])
    idx = int(input[1])

    ice[idx] = amt

next = 2*k + 1
window = sum(ice[:next])
result = window

for i in range(next, 1000001):
    window += (ice[i] - ice[i-next])
    result = max(result, window)

print(result)
