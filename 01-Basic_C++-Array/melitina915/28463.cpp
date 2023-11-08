#include<iostream>
using namespace std;

int main() {
	char dir, jump1, jump2, jump3, jump4;

	// 첫째 줄에는 진행 방향을 나타내는 알파벳 대문자 ‘E’, ‘W’, ‘S’, ‘N’ 중 하나가 주어진다.
	cin >> dir;

	// 다음 두 개의 줄에 거쳐 2 X 2 격자판이 주어진다.
	// 격자판은 오직 ‘.’, ‘I’, ‘O’, ‘P’로만 이루어져 있다.
	cin >> jump1 >> jump2;
	cin >> jump3 >> jump4;

	// 첫째 줄에 어떤 토 계열의 점프인지 출력한다.
	// 토룹은 “T”, 플립은 “F”, 러츠는 “Lz”를 출력하고,
	// 어떤 토 점프도 아니면 “?”를 출력한다.
	if (dir == 'S') {
		if (jump1 == '.' && jump2 == 'O' && jump3 == 'P' && jump4 == '.') {
			cout << 'T';
		}
		else if (jump1 == 'I' && jump2 == '.' && jump3 == '.' && jump4 == 'P') {
			cout << 'F';
		}
		else if (jump1 == 'O' && jump2 == '.' && jump3 == '.' && jump4 == 'P') {
			cout << "Lz";
		}
		else {
			cout << '?';
		}
	}
	else if (dir == 'N') {
		if (jump1 == '.' && jump2 == 'P' && jump3 == 'O' && jump4 == '.') {
			cout << 'T';
		}
		else if (jump1 == 'P' && jump2 == '.' && jump3 == '.' && jump4 == 'I') {
			cout << 'F';
		}
		else if (jump1 == 'P' && jump2 == '.' && jump3 == '.' && jump4 == 'O') {
			cout << "Lz";
		}
		else {
			cout << '?';
		}
	}
	else if (dir == 'E') {
		if (jump1 == 'O' && jump2 == '.' && jump3 == '.' && jump4 == 'P') {
			cout << 'T';
		}
		else if (jump1 == '.' && jump2 == 'P' && jump3 == 'I' && jump4 == '.') {
			cout << 'F';
		}
		else if (jump1 == '.' && jump2 == 'P' && jump3 == 'O' && jump4 == '.') {
			cout << "Lz";
		}
		else {
			cout << '?';
		}
	}
	//else if (dir == 'W') {
	else {
		if (jump1 == 'P' && jump2 == '.' && jump3 == '.' && jump4 == 'O') {
			cout << 'T';
		}
		else if (jump1 == '.' && jump2 == 'I' && jump3 == 'P' && jump4 == '.') {
			cout << 'F';
		}
		else if (jump1 == '.' && jump2 == 'O' && jump3 == 'P' && jump4 == '.') {
			cout << "Lz";
		}
		else {
			cout << '?';
		}
	}

	return 0;
}