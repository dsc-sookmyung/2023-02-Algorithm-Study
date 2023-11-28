#include <iostream>
#include <deque>
#include <stack>
using namespace std;



// 덱 - 개념 소개
// 사전적 의미
// - double-ended queue
// - 카드 덱 (deck)
// 특징
// 양쪽에서 삽입, 삭제 모두 가능
// 주요 함수
// - push_front / push_back
// - pop_front / pop_back
// front / rear
// size
// empty

// 덱 - 사례
// 실생활 예시
// - 동작그만. 밑장빼기냐?
// - 노래방 우선 예약 시스템
// 주로 언제 사용?
// - 주로 앞과 뒤에서 삽입/삭제 일어날 때
// - 데이터 개수가 가변적일 때 (메모리 공간 자동으로 확장/축소)
// - 큐를 사용하는데 회전시켜야 할 때
// - 인덱스에 접근해야 할 때 (주로 array/vector 사용)

// 덱 - 응용
// sliding window
// - 고정된 길이의 윈도우를 이동시키면서 윈도우 내의 데이터 이용
// (ex. 일정범위의 구간 내에서 최소/최대값 구할 때)
// two pointer (start & end)
// - 부분 범위의 길이가 가변적
// - 주로 정렬된 배열에서 이용
// 선형 공간을 2회 이상 반복적으로 탐색할 때 O(N^2) -> O(N)
// * 한 방향으로만 이동하면 큐로 구현 가능



// 특징 정리
// 스택 : LIFO
// 큐 : FIFO
// 덱 : double-ended queue
// 원소 삽입/삭제 O(1)



// 적절한 자료구조 선택하기
// - 문제를 읽고 어떤 선형 자료구조를 선택해야 할까?
// 1. 전체 문제를 푸는 과정에서 나오는 부분 문제를 해결할 때 써야하는 적절한 자료구조 찾기
// 2. 메인 솔루션 자체가 특정 자료구조의 개형을 이용해야 하는 경우 고려
// i) 삽입/삭제가 한 쪽 끝에서만 발생하는가? 혹은 그렇게 되도록 문제를 재해석, 변형할 수 있는가?
// -> 스택
// ii) 양쪽 끝에서 삽입/삭제가 서로 반대방향에서 발생하는가? 혹은 그렇게 되도록 문제를 재해석, 변형할 수 있는가?
// -> 큐
// iii) 양쪽 끝에서만 삽입/삭제가 모두 발생하는가? 혹은 그렇게 되도록 문제를 재해석, 변형할 수 있는가?
// -> 덱
// 1. 우선 배열 사용 고려 (머리 속에서 시뮬레이션 돌려보기)
// 2. 메모리 과다 사용 or 원소 삽입/삭제 과정이 반복되는 경우 스택, 큐, 덱 사용 고려
// 1) 큐를 강제하는 상황이라고 판단될 때
// -> 큐
// 2) 스택을 사용했을 때 풀이가 편해진다고 판단될 때
// -> 스택
// 3) 앞과 뒤에서 삽입/삭제가 자주 이루어지면
// -> 덱



int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	deque <char> dq;
	stack <int> s;

	// (1<= N <= 1000000)
	int n;
	
	// 첫째 줄에 버튼을 누른 횟수 N이 주어진다.
	cin >> n;

	// 둘째 줄부터 N개의 줄에는 버튼을 누른 순서대로 누른 버튼에 대한 정보를 주며 아래와 같은 형식으로 주어진다.
	for (int i = 0; i < n; i++) {
		int order;
		char c;
		
		cin >> order;

		// 1 c : 문자열 맨 뒤에 c가 적힌 블록 추가
		if (order == 1) {
			s.push(1);

			cin >> c;
			
			dq.push_back(c);
		}
		// 2 c : 문자열 맨 앞에 c가 적힌 블록 추가
		else if (order == 2) {
			s.push(0);

			cin >> c;
			
			dq.push_front(c);
		}
		// 3 : 문자열을 구성하는 블록 중 가장 나중에 추가된 블록 제거
		else {
			if (!s.empty()) {
				int dir = s.top();

				s.pop();

				// 1인 경우 뒤에서 빼기
				if (dir) {
					dq.pop_back();
				}
				// 0인 경우 앞에서 빼기
				else {
					dq.pop_front();
				}
			}
		}
	}

	// 완성된 문자열이 빈 문자열인 경우 0을 출력한다.
	if (dq.empty()) {
		cout << 0;
	}
	// 완성된 문자열을 출력한다. 
	else {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
		}
	}
  
	return 0;
}