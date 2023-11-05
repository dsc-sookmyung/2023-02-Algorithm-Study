#include <iostream>
using namespace std;

int main() {
	int num;
	int spare[10] = { 0, };

	for (int i = 0; i < 5; i++) {
		cin >> num;
		spare[num]++;
	}

	for (int i = 0; i < 10; i++) {
		if (spare[i] % 2 == 1) cout << i;
	}
}