import math
nn = int(input())
original = []
for i in range(0,nn):
  original += [0]

for i in range(nn):
  a = input().split(" ")
  inta = [int(x) for x in a]
  original[i] = inta



def pooh(original):
  
  poolingRow = list()
  n = len(original)
  if n == 2 :
    temp = [item for row in original for item in row]
    temp.sort()
    print(temp[2])
  else :
    for i in range(int(n/2)):
      for j in range(int(n/2)):
        square = [original[2*i][2*j], original[2*i+1][2*j], original[2*i][2*j+1], original[2*i+1][2*j+1]]
        square.sort()
        poolingRow.append(square[2])
    numCol = int(math.sqrt(len(poolingRow)))
    pooling = list()
    for i in range(int(numCol)):
      pooling.append(poolingRow[i*numCol:(i+1)*numCol])
   # print(pooling)
    pooh(pooling)

pooh(original)
