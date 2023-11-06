#include <iostream>
#include <vector>
using namespace std;

int main() {
	// 입력으로 주어지는 모든 숫자는 0이상 9이하입니다.
	vector<int> num(10);

	// 양말 5개가 주어집니다.
	// 각 양말에 쓰인 숫자 5개가 한 줄에 하나씩 주어집니다.
	for (int i = 0; i < 5; i++) {
		int sock;
		
		// 각 양말에는 숫자가 하나씩 쓰여있습니다.
		// 항상 양말을 두 개씩 두 쌍 만들 수 있는 입력만 주어집니다.
		cin >> sock;
		
		// 같은 숫자가 쓰인 양말 두 개를 모으면 양말 한 쌍이 됩니다.
		num[sock]++;
	}

	// 쌍을 만들 수 있는 양말을 두 개씩 두 쌍 빼면 남는 양말에 쓰인 숫자는 무엇인가요?
	for (int i = 0; i < 10; i++) {
		if (num[i] % 2 == 1) {
			// 첫 줄에 남는 양말에 쓰인 숫자를 출력하세요.
			cout << i;

			break;
		}
	}
}

/*
int main() {
	int sock[5] = { 0 }, num;

	for (int i = 0; i < 5; i++) {
		cin >> sock[i];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (sock[i] == sock[j]) {
				sock[i] = 0;
				sock[j] = 0;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (sock[i] != 0) {
			num = sock[i];
			break;
		}
	}

	cout << num;

	return 0;
}
*/