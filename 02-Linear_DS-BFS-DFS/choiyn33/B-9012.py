import sys
from collections import deque

n = int(input())

for _ in range(n):
    input = list(sys.stdin.readline().strip())
    stack = deque()
    isVPS = True

    for item in input:
        if item == '(':
            stack.append(item)

        elif item == ')':
            if len(stack) == 0:
                isVPS = False
                break
            else:
                if stack[-1] == '(':
                    stack.pop()
                else:
                    isVPS = False
                    break

    if len(stack) == 0 and isVPS:
        print("YES")
    else:
        print("NO")
