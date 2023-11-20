// 혜린님 코드 + 주석

#include <iostream>
using namespace std;

// 9x9 스도쿠 판과 각 행, 열, 3x3 사각형에 숫자 사용 여부를 나타내는 배열들 선언
int map[10][10];
bool row[10][10] = {
    false,
};
bool col[10][10] = {
    false,
};
bool square[10][10] = {
    false,
};

// 스도쿠 판 출력 함수
void print()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            cout << map[i][j];
        cout << '\n';
    }
}

// 스도쿠 문제를 해결하는 재귀 함수
void sudoku(int idx)
{
    // 모든 칸을 채웠으면 결과를 출력하고 프로그램 종료
    if (idx > 81)
    {
        print();
        exit(0);
    }

    // 현재 인덱스를 행과 열 좌표로 변환
    int x = (idx - 1) / 9 + 1;
    int y = (idx - 1) % 9 + 1;

    // 현재 위치가 속한 3x3 사각형의 번호 계산
    int square_num = (x - 1) / 3 * 3 + (y - 1) / 3 + 1;

    // 현재 칸이 비어있으면 가능한 모든 숫자에 대해 시도
    if (map[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (row[x][i] == false && col[y][i] == false && square[square_num][i] == false)
            {
                // 해당 숫자로 채우고 사용 여부를 업데이트
                map[x][y] = i;
                row[x][i] = true;
                col[y][i] = true;
                square[square_num][i] = true;

                // 다음 칸으로 재귀 호출
                sudoku(idx + 1);

                // 백트래킹: 다음 경우를 위해 현재 숫자를 제거하고 사용 여부를 업데이트
                map[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[square_num][i] = false;
            }
        }
    }
    else
    {
        // 현재 칸이 이미 채워져 있으면 다음 칸으로 이동
        sudoku(idx + 1);
    }
}

int main()
{
    // 입력: 초기 스도쿠 판을 읽어오고 사용된 숫자들을 체크
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            scanf("%1d", &map[i][j]);
            row[i][map[i][j]] = true;
            col[j][map[i][j]] = true;
            square[((i - 1) / 3) * 3 + (j - 1) / 3 + 1][map[i][j]] = true;
        }
    }

    // 스도쿠 문제를 해결하는 함수 호출
    sudoku(1);

    return 0;
}