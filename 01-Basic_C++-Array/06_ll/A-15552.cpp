#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); //입출력 묶음 해제
	ios_base::sync_with_stdio(false);

	int T, A, B;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << "\n";
	}
	return 0;
}
