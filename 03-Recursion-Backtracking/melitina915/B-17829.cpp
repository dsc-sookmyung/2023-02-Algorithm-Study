#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// 분할정복 - 정의
// 분할정복 (Divide and Conquer)
// - 하나의 큰 문제를 작은 문제로 분할하여 문제를 해결하는 방법
// - 문제를 둘 이상의 부분문제로 나눈 뒤 (Divide)
//   각 문제에 대한 답을 계산하고 (Conquer)
//   원래 문제에 대한 답으로 병합 (Merge)
// - 병합횟수 : logN
// -> 병합할 때 O(M)이면, 총 시간복잡도 O(MlogN)

// 분할정복 vs DP
// - 공통점
// 큰 문제를 작은 문제 여러 개로 나눠서 해결
// - 차이점
// 분할정복 : 중복되는 부분 문제 없이 완벽하게 분할
// DP : 중복되는 부분 문제 발생 -> 메모이제이션으로 해결

// 분할정복 - 구조
// - 재귀적으로 자신을 호출하면서 연산의 단위를 조금씩 줄여가는 구조
// - "F(x)가 간단" 조건을 만족할 때까지 문제를 쪼개서 답을 구하는 방식
/*
int F(x) {
	// Conquer
    if(F(x)의 문제가 간단)
		return (F(x)를 직접 계산한 값);

	// Divide
	x를 y1, y2로 분할
	F(y1)과 F(y2)를 호출

	// Merge
	return (F(y1), F(y2)로부터 F(x)를 구한 값);
}
*/

// 분할정복 - 장단점
// 장점
// - 문제를 나눔으로써 어려운 문제 해결 가능
// - 병렬적으로 문제 해결
// -> 시간 단축
// 단점
// - 함수를 재귀적으로 호출
// - 과도한 메모리 사용

// 분할정복 정리
// 분할정복 (Divide and Conquer)
// - Divide -> Conquer -> Merge
// - 중복되는 부분 문제 X (DP와의 차이점)
// - Merge 횟수 : logN
// "F(x)가 간단"해질 때까지 쪼개어 재귀 호출



// 완전탐색 - 재귀
// - 재귀함수 : 자기 자신을 호출하는 함수
// - 단순히 호출하지 않음
// -> 마지막인지 어떻게 확인할 수 있을까?
// - 재귀함수를 이용해서 문제 조건을 만족하는 경우들 생성

// 완전탐색 - 재귀함수
// - 기본 구성
// 1. 공통 작업 (선택)
// 2. 종료 조건 ( = 기저 사례)
// 3. 현재 단계에서 수행할 작업
// 4. 다음 단계 (점화식)



// 행렬의 모든 성분은 -10,000 이상 10,000 이하의 정수이다. 
int matrix[1024][1024];

// 분할정복
int divisionConquer(int half, int x, int y) {
	vector <int> v;

	// 종료 조건 ( = 기저 사례)
	// 1. 2×2 정사각형이 된 상태 or N이 홀수로 주어져서 이르게 된 상태
	if (half == 1) {
		// 현재 단계에서 수행할 작업
		// (col, row)
		// (0, 0)
		v.push_back(matrix[y][x]);
		// (0, 1)
		v.push_back(matrix[y][x + 1]);
		// (1, 0)
		v.push_back(matrix[y + 1][x]);
		// (1, 1)
		v.push_back(matrix[y + 1][x + 1]);
	}
	// 다음 단계 (점화식)
	// 1. 행렬을 2×2 정사각형으로 나눈다.
	else {
		v.push_back(divisionConquer(half / 2, x, y));
		v.push_back(divisionConquer(half / 2, x + half, y));
		v.push_back(divisionConquer(half / 2, x, y + half));
		v.push_back(divisionConquer(half / 2, x + half, y + half));
	}

	// 공통 작업 (선택)
	// 2. 각 정사각형에서 2번째로 큰 수만 남긴다.
	// 여기서 2번째로 큰 수란, 정사각형의 네 원소를 크기순으로 a4 ≤ a3 ≤ a2 ≤ a1 라 했을 때, 원소 a2를 뜻한다.
	sort(v.begin(), v.end());

	return v[2];
	// 3. 2번 과정에 의해 행렬의 크기가 줄어들게 된다.
}

int main() {
	// N은 항상 2의 거듭제곱 꼴이다. (N=2^K, 1 ≤ K ≤ 10)
	int n;

	// 첫째 줄에 N(2 ≤ N ≤ 1024)이 주어진다.
	cin >> n;

	// 다음 N개의 줄마다 각 행의 원소 N개가 차례대로 주어진다. 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	// 마지막에 남은 수를 출력한다.
	cout << divisionConquer(n / 2, 0, 0);

	return 0;
}