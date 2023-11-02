import sys 
input = sys.stdin.readline

a, b, c = map(int, input().split())
numberList = [a, b, c]
numberSet = set(numberList)

# python list의 내장함수인 count() 알게됨
if (len(numberSet) == 1):
  print(10000 + a*1000)
elif (len(numberSet) == 2):
  for i in range(3):
    countElement = numberList.count(numberList[i])
    if (countElement == 2):
      print(1000 + numberList[i]*100)
      break
elif (len(numberSet) == 3):
  maxNumber = max(a, b, c)
  print(maxNumber*100)
