#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 101;
char tile[MAX][MAX];   // 타일을 저장할 배열
int visited[MAX][MAX]; // 방문한 타일 표시할 배열
int cnt, n, m;         // cnt: 총 타일의 개수를 셀 변수, n: 세로 크기, m: 가로 크기
char now = '-';

void dfs(int i, int j)
{
    if (tile[i][j] != now)
    {
        return;
    } // now 변수(계속 업데이트된다)와 다를 경우 종료

    visited[i][j] = 1; // 방문 표시 남기기

    if (tile[i][j] == '-') // 가로 타일일 경우
    {
        if (j + 1 < m) // 옆에 타일이 있을 때
        {
            if (!visited[i][j + 1]) // 옆 타일을 방문하지 않았을 경우
            {
                dfs(i, j + 1); // now랑 달라질 때까지 오른쪽으로 이동하며 dfs를 계속해서 실행
            }
        }
    }
    else if (tile[i][j] == '|') // 세로 타일일 경우
    {
        dfs(i + 1, j); // now랑 달라질 때까지 아래쪽으로 이동하며 dfs를 계속해서 실행
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tile[i][j];
        }
    } // n줄동안 m개의 타일문자를 입력받아 tile에 저장

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j]) // 해당 타일을 방문하지 않았다면
            {
                visited[i][j] = 1;
                cnt++; // 타일 개수 추가하고

                if (tile[i][j] == '-') // 가로 타일일 경우
                {
                    if (j + 1 < m) // 마지막 타일이 아니면
                    {
                        if (!visited[i][j + 1]) // 오른쪽 타일을 방문하지 않았다면
                        {
                            now = '-';
                            dfs(i, j + 1); // 타일이 now랑 다를 때까지 오른쪽으로 이동해가며 dfs 실행
                        }
                    }
                }
                else if (tile[i][j] == '|') // 세로 타일일 경우
                {
                    if (i + 1 < n) // 마지막 타일이 아니면
                    {
                        if (!visited[i + 1][j]) // 아래 타일을 방문하지 않았을 경우
                        {
                            now = '|';
                            dfs(i + 1, j); // 타일이 now랑 다를 때까지 아래로 이동해가며 dfs 실행
                        }
                    }
                }
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}