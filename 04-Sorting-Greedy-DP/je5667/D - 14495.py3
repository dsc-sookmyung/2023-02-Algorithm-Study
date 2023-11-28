def fibonacci_like_sequence(n):
    # 기본값 설정
    if n in (1, 2, 3):
        return 1

    # n이 4 이상일 때 계산을 시작
    f = [1, 1, 1]
    for i in range(3, n):
        # f(n) = f(n-1) + f(n-3)에 따라 수열의 다음 숫자를 계산
        next_value = f[-1] + f[-3]
        f.append(next_value)
    
    # n번째 숫자 반환
    return f[-1]

# 예제 입력
n = int(input())

# 예제 출력
print(fibonacci_like_sequence(n))