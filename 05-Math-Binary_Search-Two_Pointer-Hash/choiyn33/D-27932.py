import sys

n, k = map(int, input().split())
people = list(map(int, sys.stdin.readline().split()))
people.append(people[n-1])

result = sys.maxsize


def search(low, high):
    global result
    if low > high:
        return

    mid = (low+high) // 2
    count = check(mid)

    if k < count:
        search(mid+1, high)

    else:   # 지친 사람(count)가 k명 이하일 때
        result = min(result, mid)
        search(low, mid-1)


def check(h):
    count = 0

    for i in range(n):
        me = people[i]

        if i == 0:
            after = people[i+1]

            if abs(after - me) > h:
                count += 1

        else:
            before = people[i-1]
            after = people[i+1]

            if abs(me - before) > h or abs(after - me) > h:
                count += 1

    return count


search(0, result)
print(result)
