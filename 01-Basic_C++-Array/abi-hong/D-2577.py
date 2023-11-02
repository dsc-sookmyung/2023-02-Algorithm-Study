import sys 
input = sys.stdin.readline

numberList = []
for _ in range(3):
  numberList.append(int(input()))

multiplyNum = 1
for i in numberList:
  multiplyNum *= i

multiplyNumList = [int(i) for i in str(multiplyNum)]

for i in range(10):
  print(multiplyNumList.count(i))
