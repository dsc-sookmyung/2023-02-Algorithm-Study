import sys 
input = sys.stdin.readline

n = int(input())
result = n

# 슬라이스 -> [시작인덱스:끝인덱스]
for _ in range(n):
  word = list(input())
  for i in range(len(word) - 1):
    if (word[i] == word[i+1]):
      pass
    elif (word[i] in word[i+1:]):
      result -= 1
      break
print(result)