import sys
from collections import Counter

n = int(input())
arr = sys.stdin.readline().split()

topping = list(set(arr))
cnt = 0

for item in topping:
    if item[-6:] == 'Cheese':
        cnt += 1

if cnt >= 4:
    print('yummy')
else:
    print('sad')
