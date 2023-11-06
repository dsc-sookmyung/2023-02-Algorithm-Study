#include<iostream>
#include<vector>
using namespace std;

int main() {
	// 10진법 수 N이 주어진다.
	// (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.
	// 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.
	int n, b;
	vector<char> num;

	// 첫째 줄에 N과 B가 주어진다. 
	cin >> n >> b;

	// 10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다.
	// 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다. 
	while (n > 0) {
		int r = n % b;
		char c;

		if (r < 10) {
			c = r + '0';
		}
		else {
			c = r - 10 + 'A';
		}

		num.push_back(c);
		
		n = n / b;
	}

	// 첫째 줄에 10진법 수 N을 B진법으로 출력한다.
	while (!num.empty()) {
		cout << num.back();
		num.pop_back();
	}

	return 0;
}