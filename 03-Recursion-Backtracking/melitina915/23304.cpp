#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// AKARAKA는 그 자체로도 팰린드롬이고,
// 접두사이자 접미사인 AKA가 또한 팰린드롬이기 때문이다.
bool akarakapalindrome(string s) {
	int len = s.length();

	if(len != 1) {
		string word = s;

		// 문자열 S가 팰린드롬이다.
		// 팰린드롬이란 거꾸로 뒤집어 읽어도 같은 문자열을 뜻한다.
		reverse(s.begin(), s.end());

		if (word != s) {
			return false;
		}
		else {
			string affix = s.substr(0, len / 2);

			// 문자열 S의 길이를 |S|라 할 때,
			// ㅏ| S |ㅓ 길이의 접두사와 접미사가 모두 아카라카 팰린드롬이다.
			if (!akarakapalindrome(affix)) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	// 만약 |S| = 1이면, S는 아카라카 팰린드롬이다.
	else {
		return true;
	}
}

int main() {
	// ( 1 <= | S | <= 2000000 )
	string s;

	// 알파벳 소문자로 이루어진 문자열 S가 주어진다.
	cin >> s;

	// 주어진 문자열 S가 아카라카 팰린드롬이라면, AKARAKA를 출력한다.
	if (akarakapalindrome(s)) {
		cout << "AKARAKA";
	}
	// 만약 그렇지 않다면, IPSELENTI를 출력한다.
	else {
		cout << "IPSELENTI";
	}

	return 0;
}