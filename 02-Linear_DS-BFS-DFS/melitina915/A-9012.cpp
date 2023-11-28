#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 자료구조란?
// - 자료(data)의 집합
// - 효율적인 접근 및 수정을 가능케 하는 자료이 조직, 관리, 저장
// - 선형/비선형

// 선형 자료구조
// - 자료 간 관계가 1:1인 선형 구조
// 스택, 큐, 덱

// 비선형 자료구조
// - 자료 간 관계가 1:n 혹은 n:n 구조인 비선형 구조
// 그래프, 트리

// 스택 - 개념 소개
// 사전적 의미
// - 무더기, 더미
// - 쌓다, 쌓아서 채우다
// 특징
// - LIFO (Last In First Out)
// 주요 함수
// - push
// - pop
// - top
// - size
// - empty

// 스택 - 사례
// 실생활 예시
// - 프링글스
// - 웹 브라우저 기록
// - 함수 호출
// 주로 언제 사용?
// - 중간 원소를 삽입/삭제/탐색하지 않는 경우
// - 후위 표기법 계산
// * 후위 표기법 : 피연산자 뒤에 연산자가 오는 형식
// 괄호를 없애는 과정이 스택과 유사

// 스택 - 응용
// 재귀 알고리즘
// - 함수에서 자신을 다시 호출하여 작업을 수행하는 방식
// - 순열 만들기
// 모노톤 스택 (monotone stack)
// - 단조로운 스택
// - 오름/내림차순을 유지한 스택
// 중복없는 내림차순
// - top <= 들어가려는 수일 때 pop 반복



// 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 
// 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 
// 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 
bool vps(string str) {
	int len = str.length();
	stack<char> st;

	for (int i = 0; i < len; i++) {
		char c = str[i];

		if (c == '(') {
			st.push(str[i]);
		}
		else if (!st.empty()) {
			st.pop();
		}
		else {
			return false;
		}
	}

	return st.empty();
}

int main(void) {
	// 입력은 T개의 테스트 데이터로 주어진다.
	int n;

	// 입력 데이터는 표준 입력을 사용한다.
	// 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다.
	cin >> n;

	for (int i = 0; i < n; i++) {
		// 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 
		string str;

		// 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다.
		cin >> str;

		// 출력은 표준 출력을 사용한다. 
		// 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”,
		// 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 
		if (vps(str)) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
