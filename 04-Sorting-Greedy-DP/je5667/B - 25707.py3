from itertools import permutations

def get_input():
    n = int(input())  # 숫자의 개수 입력
    numbers = list(map(int, input().split()))  # 숫자 입력 및 리스트 변환
    if len(numbers) != n:
        raise ValueError("입력된 숫자의 개수가 맞지 않습니다.")
    return numbers

numbers = get_input()

def find_min_distance(numbers):
    # 숫자들을 정렬합니다. 정렬함으로써 인접한 두 수의 차이가 최소가 됩니다.
    numbers.sort()

    # 숫자들의 배열을 두 부분으로 나누고, 각각을 원형에서 대칭되는 위치에 배치합니다.
    # 예를 들어, 1 3 5 7 9가 있으면, 1 5 9와 3 7을 대칭으로 배치합니다.
    # 이렇게 하면, 원형 배열에서 인접한 두 수의 차이가 최소가 됩니다.
    half = len(numbers) // 2
    left_side = numbers[:half]
    right_side = numbers[half:]

    # 원형 배열에서 최소 거리의 합을 계산합니다.
    min_distance_sum = 0
    for i in range(half - 1):
        min_distance_sum += (right_side[i + 1] - left_side[i])
        min_distance_sum += (left_side[i + 1] - right_side[i])

    # 첫 번째와 마지막 요소를 추가로 계산합니다.
    min_distance_sum += (right_side[0] - left_side[0])
    if len(numbers) % 2 == 0:
        min_distance_sum += (right_side[-1] - left_side[-1])
    else:
        min_distance_sum += (right_side[-1] - left_side[-1]) + (right_side[-1] - right_side[-2])

    return min_distance_sum

print(find_min_distance(numbers))
