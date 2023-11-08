#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	// 어떤 단어를 뒤에서부터 읽어도 똑같다면 그 단어를 팰린드롬이라고 한다.
	string num, palindrome;

	// 입력은 여러 개의 테스트 케이스로 이루어져 있으며,
	// 각 줄마다 1 이상 99999 이하의 정수가 주어진다. 
	cin >> num;

	// 입력의 마지막 줄에는 0이 주어지며, 이 줄은 문제에 포함되지 않는다.
	while (num != "0") {
		palindrome = num;

		// 수의 숫자들을 뒤에서부터 읽어도 같다면 그 수는 팰린드롬수다.
		reverse(palindrome.begin(), palindrome.end());

		// 각 줄마다 주어진 수가 팰린드롬수면 'yes', 아니면 'no'를 출력한다.
		if (num == palindrome) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

		cin >> num;
	}

	return 0;
}