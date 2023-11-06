#include<iostream>
using namespace std;

int factorial(int num) {
	if (num <= 1) {
		return 1;
	}
	else {
		return factorial(num - 1) * num;
	}
}

int main() {
	// (1 ≤ N ≤ 10, 0 ≤ K ≤ N )
	int n, k;

	// 첫째 줄에 N과 K가 주어진다.
	cin >> n >> k;

	// 자연수 N과 정수 K가 주어졌을 때 이항 계수 NCK를 구하는 프로그램을 작성하시오.
	// NCK를 출력한다.
	cout << factorial(n) / (factorial(k) * factorial(n - k));

	return 0;
}