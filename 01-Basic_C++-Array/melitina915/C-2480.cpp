#include <iostream>
using namespace std;

int main() {
	// 1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다. 
	int dice1, dice2, dice3, price, maximum;

	// 첫째 줄에 3개의 눈이 빈칸을 사이에 두고 각각 주어진다. 
	cin >> dice1 >> dice2 >> dice3;

	// 3개 주사위의 나온 눈이 주어질 때, 상금을 계산하는 프로그램을 작성 하시오.
	
	// 1. 같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
	if (dice1 == dice2 && dice2 == dice3) {
		price = 10000 + dice1 * 1000;
	}
	// 2. 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다. 
	else if (dice1 == dice2 || dice2 == dice3) {
		price = 1000 + dice2 * 100;
	}
	else if (dice3 == dice1) {
		price = 1000 + dice3 * 100;
	}
	// 3. 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다. 
	else {
		//maximum = max({ dice1, dice2, dice3 });
		maximum = max(max(dice1, dice2), dice3);
		price = maximum * 100;

		/*
		max = dice1;
		if (dice2 > max) {
			max = dice2;
		}
		if (dice3 > max) {
			max = dice3;
		}
		price = max * 100;
		*/
	}

	// 첫째 줄에 게임의 상금을 출력 한다.
	cout << price;

	return 0;
}