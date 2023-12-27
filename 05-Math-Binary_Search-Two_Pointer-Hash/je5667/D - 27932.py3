def binary_search(low, high):
    global result
    if low > high:
        return

    mid = (low + high) // 2
    count = check(mid)

    if count > K:
        binary_search(mid + 1, high)
    else:
        result = min(result, mid)
        binary_search(low, mid - 1)

def check(H):
    count = 0
    for i in range(N):
        if i == 0:
            # Comparing the first element with the second
            me = arr[i]
            after = arr[i + 1]
            if abs(me - after) > H:
                count += 1
        else:
            # For other elements, comparing with the previous and next
            before = arr[i - 1]
            me = arr[i]
            after = arr[i + 1]
            if abs(me - before) > H or abs(me - after) > H:
                count += 1
    return count

if __name__ == "__main__":
    N, K = map(int, input().split())  # 사람의 인원 수, 지친 사람이 K명 이하가 되어야 함
    arr = list(map(int, input().split()))
    arr.append(arr[-1])  # Adding the last element again to avoid index out of range

    result = float('inf')
    binary_search(0, max(arr) - min(arr))  # Setting upper limit based on potential maximum difference
    print(result)