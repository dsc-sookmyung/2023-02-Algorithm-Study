from collections import deque
import sys

n = int(input())
d = deque()     # 문자열 저장을 위한 덱
s = deque()     # 명령어 저장을 위한 스택

for _ in range(n):
    input = sys.stdin.readline().split()

    if input[0] == '1':
        d.append(input[1])
        s.append(1)

    elif input[0] == '2':
        d.appendleft(input[1])
        s.append(2)

    else:
        if len(d) != 0:
            if s.pop() == 1:
                d.pop()
            else:
                d.popleft()

if len(d) == 0:
    print("0")
else:
    result = ''.join(d)
    print(result)
