#include<iostream>
using namespace std;

// 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.
int a[100][100] = { 0 }, b[100][100] = { 0 }, c[100][100] = { 0 };
int product[100][100] = { 0 };

void matrix(int n, int m, int k) {
	// N* M크기의 행렬 A와 M* K크기의 행렬 B가 주어졌을 때,
	// 두 행렬을 곱하는 프로그램을 작성하시오.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int v = 0; v < m; v++) {
				// n x k = n x m * m x k
				product[i][j] += a[i][v] * b[v][j];
			}

			// 첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다.
			cout << product[i][j] << " ";
		}

		// 행렬의 각 원소는 공백으로 구분한다.
		cout << '\n';
	}
}

int main() {
	// N과 M, 그리고 K는 100보다 작거나 같고, 
	int n, m, k;
	
	// 첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 
	cin >> n >> m;

	// 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	// 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 
	cin >> m >> k;

	// 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다.
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}

	matrix(n, m, k);

	return 0;
}