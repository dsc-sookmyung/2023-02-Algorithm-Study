#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> snow(101); // 눈덩이의 크기를 저장하는 벡터

int N, M;       // N은 눈덩이의 개수, M은 눈덩이 조작 횟수
int answer = 0; // 최대 크기의 눈덩이를 저장하는 변수

void func(int time, int size, int pos)
{
    if (time == M or pos >= N)
    {
        // 눈덩이를 조작할 횟수에 도달하거나 배열을 벗어난 경우
        answer = max(size, answer); // 현재까지의 눈덩이 크기 중 최대값을 업데이트
        return;
    }

    for (int i = 1; i <= 2; i++)
    {
        if (i == 1)
        {
            // 눈덩이를 굴리는 경우
            func(time + 1, size + snow[pos + i], pos + i);
        }
        else
        {
            // 눈덩이를 던지는 경우
            func(time + 1, (size / 2) + snow[pos + i], pos + i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M; // 눈덩이의 개수와 눈덩이 조작 횟수 입력 받기

    for (int i = 1; i <= N; i++)
    {
        cin >> snow[i]; // 각 눈덩이의 크기 입력 받기
    }

    func(0, 1, 0);  // 초기 상태에서 재귀 함수 호출
    cout << answer; // 최대 눈덩이 크기 출력

    return 0;
}
