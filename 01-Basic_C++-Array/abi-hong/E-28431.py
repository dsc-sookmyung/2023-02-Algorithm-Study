import sys 
input = sys.stdin.readline

socks = set()
result = 0

for _ in range(5):
  sock = int(input())
  if (sock in socks):
    result -= sock
    socks.discard(sock)
  else:
    socks.add(sock)
    result += sock
print(result)