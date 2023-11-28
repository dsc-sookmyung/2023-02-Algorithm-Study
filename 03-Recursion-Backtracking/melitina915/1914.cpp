#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void hanoi(int n, int a, int b, int c);

int main() {
	int n;

	// 첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N (1 ≤ N ≤ 100)이 주어진다.
	cin >> n;

	// k = 2^n
	string k = to_string(pow(2, n));

	// pow 함수 결과가 실수형
	int finddot = k.find('.');

	// 소수점 앞자리까지 저장
	k = k.substr(0, finddot);

	// 하노이 탑에 대한 원판 이동 횟수 = 2^x - 1
	k[k.length() - 1] -= 1;

	// 첫째 줄에 옮긴 횟수 K를 출력한다.
	cout << k << '\n';

	// N이 20 이하인 입력에 대해서는 두 번째 줄부터 수행 과정을 출력한다.
	// 두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데,
	// 이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다. 
	if (n <= 20) {
		// n개의 원반을 1번 기둥에서 2번 기둥을 거쳐 3번 기둥으로 옮기는 것이 목표
		hanoi(n, 1, 3, 2);
	}
	// N이 20보다 큰 경우에는 과정은 출력할 필요가 없다.

	return 0;
}

void hanoi(int n, int start, int end, int tmp) {
	if (n == 1) {
		cout << start << ' ' << end << '\n';

		return;
	}
	else {
		// n - 1개의 원반을 1번 기둥에서 3번 기둥을 거쳐 2번 기둥으로 옮긴다
		hanoi(n - 1, start, tmp, end);

		// 남았던 1개의 원반을 1번 기둥에서 3번 기둥으로 옮긴다
		cout << start << ' ' << end << '\n';

		// 2번 기둥으로 옮겼던 n - 1개의 원반을 2번 기둥에서 1번 기둥을 거쳐 3번 기둥으로 옮긴다
		hanoi(n - 1, tmp, end, start);
	}
}