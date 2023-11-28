#include <iostream>
using namespace std;

// 0 ≤ r, c < 2^N
int r, c, cnt;

// N이 주어졌을 때,
// r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.
// y,x는 현재 탐색하고자 하는 사분면의 가장 왼쪽 위 좌표
// size는 현재 사분면 한 변의 길이
void z(int y, int x, int size) {
	// 그렇게 호출 되면서
	// y,x값이 r,c값과 일치하면 최종적으로 답을 출력하고 return
	if (y == r && x == c) {
		// r행 c열을 몇 번째로 방문했는지 출력한다.
		cout << cnt << '\n';

		return;
	}
	// 한수는 크기가 2^N × 2^N인 2차원 배열을 Z모양으로 탐색하려고 한다.
	// 찾고자 하는 좌표 값 r,c가 현재 사분면 내에 존재할 경우
	// 현재 사분면을 다시 4등분하여,
	// 현재 4분면의 1,2,3,4 분면 각각의 재귀함수를 호출
	// 예를 들어, 2×2배열을
	if (r < y + size && r >= y && c < x + size && c >= x) {
		// 왼쪽 위칸,
		z(y, x, size / 2);
		// 오른쪽 위칸,
		z(y, x + size / 2, size / 2);
		// 왼쪽 아래칸, 
		z(y + size / 2, x, size / 2);
		// 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
		z(y + size / 2, x + size / 2, size / 2);
	}
	// N > 1인 경우,
	// 배열을 크기가 2^(N - 1) × 2^(N - 1)로 4등분 한 후에 재귀적으로 순서대로 방문한다.
	// 만약 r,c가 현재 사분면 내에 존재하지 않을 경우
	// 현재 사분면을 탐색할 필요가 없으므로
	// cnt에 현재 사분면의 크기 size^2을 더해준 후 return
	else {
		cnt += size * size;
	}
}

int main() {
	// 1 ≤ N ≤ 15
	int n;

	// 첫째 줄에 정수 N, r, c가 주어진다.
	cin >> n >> r >> c;

	z(0, 0, (1 << n));

	return 0;
}