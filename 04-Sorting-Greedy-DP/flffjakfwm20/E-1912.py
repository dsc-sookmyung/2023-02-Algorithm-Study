import sys 
input = sys.stdin.readline

n = int(input())
nums = list(map(int, input().split()))
# 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합
# 이전까지의 합이, 그냥 i번째 숫자보다 작은 경우 이전의 기록들은 무의미하다. 그러니 그냥 i번째 숫자를 최대값으로 설정한다. 
for i in range(1, n):
  nums[i] = max(nums[i], nums[i-1] + nums[i])

print(max(nums))