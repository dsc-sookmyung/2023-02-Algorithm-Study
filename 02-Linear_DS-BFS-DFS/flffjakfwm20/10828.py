import sys 
input = sys.stdin.readline

n = int(input())
stack = []

for _ in range(n):
  order = list(input().split())
  
  if (order[0] == 'push'): # 정수 X를 스택에 넣는 연산이다.
    stack.append(order[1])
  elif (order[0] == 'pop'): # 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    if (len(stack) == 0):
      print('-1')
    else: 
      pop_num = stack.pop()
      print(pop_num)
  elif (order[0] == 'size'): # 스택에 들어있는 정수의 개수를 출력한다.
    print(len(stack))
  elif (order[0] == 'empty'): # 스택이 비어있으면 1, 아니면 0을 출력한다.
    if (len(stack) == 0):
      print('1')
    else:
      print('0')
  elif (order[0] == 'top'): # 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    if (len(stack) == 0):
      print('-1')
    else:
      print(stack[len(stack)-1])