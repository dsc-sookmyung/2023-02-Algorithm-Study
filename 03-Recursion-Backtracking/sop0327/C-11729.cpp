#include <iostream>
using namespace std;

// 하노이 탑 이동을 수행하는 함수
// n: 원판의 개수, start: 출발 기둥, to: 도착 기둥, bypass: 경유 기둥
void hanoi(int n, int start, int to, int bypass)
{
    if (n == 1)
        printf("%d %d\n", start, to);
    else
    {
        // n-1개의 원판을 경유 기둥으로 이동
        hanoi(n - 1, start, bypass, to);
        // 가장 큰 원판을 도착 기둥으로 이동
        printf("%d %d\n", start, to);
        // 경유 기둥에 있는 n-1개의 원판을 도착 기둥으로 이동
        hanoi(n - 1, bypass, to, start);
    }
}

int main()
{
    int num;
    cin >> num; // 사용자로부터 하노이 탑의 층 수 입력 받기

    cout << (1 << num) - 1 << "\n"; // 하노이 탑을 모두 이동하는 횟수 계산 및 출력

    hanoi(num, 1, 3, 2); // 하노이 탑 이동을 위해 함수 호출

    return 0;
}
