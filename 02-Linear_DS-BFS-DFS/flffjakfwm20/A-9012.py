import sys 
input = sys.stdin.readline

t = int(input())
for _ in range(t):
  input_str = list(input().strip())
  
  stack = []
  for i in input_str:
    if (len(stack) == 0):
      stack.append(i)
    else:
      if (i == ')' and stack[-1] == '('):
        stack.pop()
      else:
        stack.append(i)
  if (len(stack) == 0):
    print('YES')
  else:
    print('NO')