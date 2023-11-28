#include <iostream>
#include <algorithm>
using namespace std;



// 그래프 탐색 - 정의
// 그래프 탐색 (Graph Search)
// - 그래프의 한 정점에서 출발해서 모든 정점을 한 번씩 방문하는 것
// - 그래프에 대한 정보를 얻거나, 정점들을 방문한 순서를 이용하기 위해 사용함
// 깊이 우선 탐색 (Depth-First Search)
// - '깊이'를 우선으로 탐색하는 알고리즘
// 너비 우선 탐색 (Breadth-First Search)
// - '너비'를 우선으로 탐색하는 알고리즘

// 그래프 탐색 - DFS
// 깊이 우선 탐색 (Depth-First Search)
// - 깊이가 깊어지는 방향으로 그래프를 탐색하는 알고리즘
// 구현 방법
// - 스택
// - 재귀 함수
// 활용
// - 백트래킹
// - 사이클 검출

/*
void dfs(int start){
	stack<int> st;
	st.push(start);
	visited[start] = 1;

	while (!st.empty()) {
		int cur = st.top();
		st.pop();

		for (int next : adj[cur]) {
			if(!visited[next]){
				visited[next] = 1;
				st.push(next);
			}
		}
	}
}

void dfs(int cur){
	visited[cur] = 1;
	
	for (auto &next : adj[cur]) {
		if(!visited[next]){
			dfs(next);
		}
	}
}
*/



// 백트래킹 - 정의
// 백트래킹이란? backtracking
// - 한정된 조건을 가진 문제를 풀려는 전략
// - 가지치기(Pruning)
// - 시간이 오래 걸린다는 완전탐색의 단점 보완
// - 간단한 백트래킹 문제는 기본 구성에서 크게 벗어나지 X

// 백트래킹 - 구조
// - 주로 재귀함수로 구현
// 1. 종료 조건
// 2. 반복문
// 3. 제한 조건
// 4. 상태 변화
// 5. 다음 단계
// 6. 원상 복구

// 완전탐색 vs 백트래킹
// 완전탐색
// - 가능한 모든 경우의 수 탐색
// - 시간이 오래 걸림
// - 브루트포스, DFS/BFS
// 백트래킹
// - 가지치기를 통해 조건에 어긋나는 경우는 탐색 X
// - 완전탐색보다 시간 단축 (제한 조건 많을수록 더 많이 단축)
// - 주로 재귀함수로 구현
// 문제풀이 tip
// - 일단 완전탐색으로 풀었을 때의 시간복잡도 계산
// -> 가능할 것 같으면 한 번 풀어보고
// -> 시간초과 날 것 같으면 백트래킹 시도



// 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.
int num[9], seq[9];
// N개의 자연수는 모두 다른 수이다.
// N개의 자연수와 자연수 M이 주어졌을 때, 
// 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
// (1 ≤ M ≤ N ≤ 7)
int n, m;

void dfs(int cnt) {
	// 1. 종료 조건
	// 3. 제한 조건
	// m개가 다 차면 출력
	// 목표인 m까지 도달한 경우
	if (cnt == m) {
		// 중복되는 수열을 여러 번 출력하면 안되며,
		// 각 수열은 공백으로 구분해서 출력해야 한다.
		// N개의 자연수 중에서 M개를 고른 수열
		// seq에 저장한 값 m개 만큼 출력
		for (int i = 0; i < m; i++) {
			cout << seq[i] << ' ';
		}

		// 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
		cout << '\n';

		// 6. 원상 복구
		return;
	}
	// 2. 반복문
	// 같은 수를 여러 번 골라도 된다.
	// 목표인 m까지 도달하지 못한 경우
	else {
		for (int i = 0; i < n; i++) {
			// 4. 상태 변화
			// 정렬한 n값을 seq에 저장
			seq[cnt] = num[i];
			// 5. 다음 단계
			// 더 깊게 m까지 들어간다
			dfs(cnt + 1);
		}
	}
}

int main() {
	// 첫째 줄에 N과 M이 주어진다.
	cin >> n >> m;

	// 둘째 줄에 N개의 수가 주어진다. 
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	// 수열은 사전 순으로 증가하는 순서로 출력해야 한다.
	sort(num, num + n);

	dfs(0);

	return 0;
}