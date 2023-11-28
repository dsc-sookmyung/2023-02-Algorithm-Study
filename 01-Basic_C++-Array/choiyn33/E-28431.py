import sys
data = [sys.stdin.readline().strip() for i in range(5)]

socks = [0] * 10

for i in data:
    socks[int(i)] += 1

for i in range(len(socks)):
    if (socks[i] % 2 != 0):
        print(i)
