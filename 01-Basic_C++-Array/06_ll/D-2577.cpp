#include <iostream>
using namespace std;

int main() {
	int A, B, C, n;
	cin >> A;
	cin >> B;
	cin >> C;
	int mul = A * B * C;

	int num[10] = { 0, };
	
	while (mul) {
		n = mul % 10;
		num[n]++;
		mul = mul / 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << num[i] << "\n";
	}
}
