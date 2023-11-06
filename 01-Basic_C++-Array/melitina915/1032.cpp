#include <iostream>
#include <string>
using namespace std;

// 이 문제는 검색 결과가 먼저 주어졌을 때,
// 패턴으로 뭘 쳐야 그 결과가 나오는지를 출력하는 문제이다.
// 패턴에는 알파벳과 "." 그리고 "?"만 넣을 수 있다. 
int main() {
	// N은 50보다 작거나 같은 자연수이고 파일 이름의 길이는 모두 같고 길이는 최대 50이다. 
	int n;
	// 파일이름은 알파벳 소문자와 '.' 로만 이루어져 있다.
	string file, name;

	// 첫째 줄에 파일 이름의 개수 N이 주어진다.
	cin >> n;

	// 둘째 줄부터 N개의 줄에는 파일 이름이 주어진다.
	cin >> file;


	for (int i = 1; i < n; i++) {
		cin >> name;

		// 그 디렉토리에는 검색 결과에 나온 파일만 있다고 가정하고,
		// 파일 이름의 길이는 모두 같다.
		for (int j = 0; j < file.length(); j++) {
			if (file[j] != name[j]) {
				// 가능하면 ?을 적게 써야 한다.
				file[j] = '?';
			}
		}

	}

	cout << file;

	return 0;
}