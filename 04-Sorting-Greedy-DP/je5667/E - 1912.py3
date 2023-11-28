1912 
def max_subarray_sum(numbers):
    # 최대 부분합을 찾기 위한 변수 초기화
    max_sum = current_sum = numbers[0]

    # 리스트의 첫 번째 값을 이미 사용했으므로, 두 번째 원소부터 순회
    for number in numbers[1:]:
        # 현재 원소를 포함하는 것과 포함하지 않는 것 중 더 큰 합을 선택
        current_sum = max(number, current_sum + number)
        # 현재까지의 최대 부분합 업데이트
        max_sum = max(max_sum, current_sum)

    return max_sum

def get_input():
    n = int(input())  # 숫자의 개수 입력
    numbers = list(map(int, input().split()))  # 숫자 입력 및 리스트 변환
    if len(numbers) != n:
        raise ValueError("입력된 숫자의 개수가 맞지 않습니다.")
    return numbers

numbers1 = get_input()

# 예제 입력 1
#numbers1 = [10, -4, 3, 1, 5, 6, -35, 12, 21, -1]

# 예제 출력 1
print(max_subarray_sum(numbers1)) #33

# 예제 입력 2
#numbers2 = [2, 1, -4, 3, 4, -4, 6, 5, -5, 1]

# 예제 출력 2
#print(max_subarray_sum(numbers2)) #14
