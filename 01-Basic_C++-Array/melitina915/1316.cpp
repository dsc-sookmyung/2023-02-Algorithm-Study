#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	// N은 100보다 작거나 같은 자연수이다.
	int n, cnt = 0;
	// 그룹 단어란 단어에 존재하는 모든 문자에 대해서,
	// 각 문자가 연속해서 나타나는 경우만을 말한다.
	string word;

	// 첫째 줄에 단어의 개수 N이 들어온다.
	cin >> n;

	// 단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
	for (int i = 0; i < n; i++) {
		bool group = true;

		// 둘째 줄부터 N개의 줄에 단어가 들어온다.
		// 단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
		cin >> word;
		
		word.erase(unique(word.begin(), word.end()), word.end());

		sort(word.begin(), word.end());

		for (int j = 0; j < word.length() - 1; j++) {
			if (word[j] == word[j + 1]) {
				group = false;
				break;
			}
		}

		if (group) {
			cnt++;
		}
	}

	// 첫째 줄에 그룹 단어의 개수를 출력한다.
	cout << cnt;

	return 0;
}