import sys 
input = sys.stdin.readline

n = int(input())

# 원반 개수 n을 입력 받아, 모든 원반을 다른 막대에 옮기는 각 움직을 출력
def hanoi(n, start, end):
  if (n == 1):
    print(start, end)
    return
  # 첫 번째 재귀에서는 맨 밑의 N번째 원반을 목적지로 옮기기 위해 위의 N-1 개의 원반을 경유지로 옮긴다.
  hanoi(n-1, start, 6-start-end)
  # 그 다음 N 번째 원반을 목적지로 옮긴다.
  print(start, end)
  # 경유지에 있는 N-1 개의 원반을 end로 옮긴다.
  hanoi(n-1, 6-start-end, end)

print(2**n - 1)
hanoi(n, 1, 3)