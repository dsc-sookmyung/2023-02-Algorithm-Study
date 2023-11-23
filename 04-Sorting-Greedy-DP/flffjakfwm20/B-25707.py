import sys 
input = sys.stdin.readline

#  N개의 구슬로 팔찌를 만들되 줄을 가능한 적게 사용
n = int(input())
circle = list(map(int, input().split()))
circle.sort() # 정렬을 왜 해야하는지?

result = 0 
for i in range(n-1):
  result += abs(circle[i+1] - circle[i])
result += abs(circle[0] - circle[n-1])
print(result)