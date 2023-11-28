import sys 
input = sys.stdin.readline

# DP식 정의 -> n번째 피보나치 비스무리한 수열
# 초기 조건 찾기 -> f(1) = f(2) = f(3) = 1
# 점화식 세우기 -> f(n) = f(n-1) + f(n-3)
n = int(input())
dp = [-1 for i in range(117)]
dp[0] = 0
dp[1] = 1
dp[2] = 1
dp[3] = 1

def nearest_pibo(n):
  if (n <= 3): 
    return dp[n]
  if (dp[n] != -1):
    return dp[n]
  dp[n] = nearest_pibo(n-1) + nearest_pibo(n-3)
  return dp[n]
print(nearest_pibo(n))