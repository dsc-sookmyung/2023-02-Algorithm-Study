#define _CRT_SECURE_NO_WARNINGS
// Visual Studio 컴파일러의 일부 보안 경고를 무시하기 위한 지시문

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 1025
// 배열의 최대 크기를 나타내는 매크로

#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)
// 두 변수를 교환하는 매크로

using namespace std;

int N, remember_N;
int falling[MAX_SIZE][MAX_SIZE];
queue<int> q;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> falling[i][j];
        }
    }
    remember_N = N;
}

bool compare(int a, int b)
{
    if (a > b)
        return true;
    else
        return false;
}
// 정렬 함수에 사용되는 비교 함수

void func(int x, int y)
{
    vector<int> v;
    for (int i = x; i < x + 2; i++)
    {
        for (int j = y; j < y + 2; j++)
        {
            v.push_back(falling[i][j]);
        }
    }
    sort(v.begin(), v.end(), compare);
    q.push(v.at(1));
    v.clear();
}
// 2x2 부분 배열에서 두 번째로 큰 값을 큐에 추가하는 함수

void Falling_Down(int size, int x, int y)
{
    int n = size / 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            func(x + i * 2, y + j * 2);
        }
    }
    remember_N = n;
}
// 배열을 2x2 부분 배열로 나누어 두 번째로 큰 값들을 큐에 추가하는 함수

int main()
{
    input();
    while (1)
    {
        Falling_Down(N, 0, 0);
        if (remember_N == 1)
            break;
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                int data = q.front();
                q.pop();
                falling[i][j] = data;
            }
        }
        N = N / 2;
    }

    cout << q.front();
    return 0;
}
// 주어진 배열을 나누어 두 번째로 큰 값들을 찾고, 계속해서 반복하여 최종적으로 큐에 남은 값을 출력하는 메인 함수
