#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int num;
    cin >> num;

    // 상단 삼각형 출력
    for (int i = 1; i <= num; i++) {
        string stars(i, '*');
        string spaces((num - i) * 2, ' ');
        cout << stars << spaces << stars << endl;
    }

    // 하단 삼각형 출력
    for (int j = num-1; j >= 0; j--) {
        string stars(j, '*');
        string spaces((num - j) * 2, ' ');
        cout << stars << spaces << stars << endl;
    }

    return 0;
}
