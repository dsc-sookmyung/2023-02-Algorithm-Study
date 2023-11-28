#include <iostream>
using namespace std;

int n, num[100000] = { 0 }, dp[100000] = { 0 }, sum;

int main() {
	// 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

	// 첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 
	cin >> n;

	// 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다.
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	// 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중
	// 가장 큰 합을 구하려고 한다. 
	sum = num[0];

	// 단, 수는 한 개 이상 선택해야 한다.
	for (int i = 0; i < n; i++) {
		dp[i] = num[i];

		if (i == 0) {
			continue;
		}

		// 연속된 수일 경우
		// 자기 자신보다 이전의 연속합에 자기 자신을 더한 것이 클 때
		if (dp[i] < dp[i - 1] + num[i]) {
			// 큰 값을 선택
			dp[i] = dp[i - 1] + num[i];
		}

		// 연속된 수가 아닐 경우
		if (dp[i] > sum) {
			// 자기 자신만을 가지고 간다
			sum = dp[i];
		}
	}

	// 첫째 줄에 답을 출력한다.
	cout << sum << '\n';

	return 0;
}