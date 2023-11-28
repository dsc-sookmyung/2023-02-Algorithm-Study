import sys 
input = sys.stdin.readline

n, m = map(int, input().split())
nums = sorted(list(map(int, input().split())))
result_num = []

# N개의 자연수 중에서 M개를 고른 수열
# 같은 수를 여러 번 골라도 된다.
def make():
  if (len(result_num) == m):
    print(' '.join(map(str, result_num)))
    return
  for i in range(n):
    result_num.append(nums[i])
    make()
    result_num.pop()

make()