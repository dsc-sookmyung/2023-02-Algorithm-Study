#include <iostream>
using namespace std;

// 예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
int main() {
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int n;

	// 첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
	cin >> n;

	// 첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.
	for (int i = 0; i < n; i++) {
		//cout << '*' * (i + 1) + ' ' * (n - 1 - i) << '\n';
		for (int j = 0; j < i + 1; j++) {
			cout << '*';
		}
		for (int j = 0; j < (n - 1 - i); j++) {
			cout << "  ";
		}
		for (int j = 0; j < i + 1; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = i; j > 0; j--) {
			cout << '*';
		}
		for (int j = 0; j < n - i; j++) {
			cout << "  ";
		}
		for (int j = i; j > 0; j--) {
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}