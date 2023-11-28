import sys 
input = sys.stdin.readline

n, k = map(int, input().split())
q = [i for i in range(1, n+1)]
result = []
index = 0

while q:
  index += k - 1
  if (index >= len(q)):
    index %= len(q)
  result.append(str(q.pop(index)))

print('<' + ', '.join(result) + '>')