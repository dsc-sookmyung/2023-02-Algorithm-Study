#include <iostream>
using namespace std;



// 트리

// 트리 - 소개
// 그래프 - 정의
// 그래프 (Graph) G
// - 정점(vertex, node)과 간선(edge, link)의 집합으로 이루어진 자료구조
// - G = (V, E)로 표현
// 그래프 > 연결 그래프 (connected graph)
// - 임의의 두 정점 사이에 경로가 존재하는 그래프
// - 모든 연결그래프는 spanning tree를 만들 수 있음
// -> 그래프 내의 모든 정점을 포함하는 트리
// -> 그래프의 부분집합
// 순환 그래프 (cycle graph)
// - 순환(cycle)을 가지고 있는 그래프
// 비순환 그래프 (acyclic graph)
// - 순환(cycle)을 가지지 않는 그래프
// - ex) Tree, DAG
// 그래프 > 연결그래프 > 트리
// - 트리는 연결그래프이면서 비순환 그래프
// 연결그래프 (교집합) 비순환그래프

// 트리 - 용어정리
// 노드 : 트리를 구성하는 정점
// 간선 : 부모노드와 자식노드관계의 연결선
// 루트노드 : 트리의 시작 노드
// 리프노드 : 자식 노드가 없는 노드
// 부모(자식)노드 : 연결된 두 노드 중 상위(하위) 노드
// 형제노드 : 동일한 부모 노드를 갖는 노드들
// 조상노드 : 부모 노드들의 집합
// 자손노드 : 자식 노드들의 집합
// 서브트리 : 어떤 노드 n과 그 자손들로 구성된 트리
// 차수
// - 노드의 차수 : 노드에 연결된 자식 노드의 수
// - 트리의 차수 : 트리에 있는 노드의 차수 중 최댓값
// 노드의 레벨 : 루트노드 ~ 현재노드까지의 간선 수
// 높이
// - 노드의 높이 : 노드의 레벨
// - 트리의 높이 : 트리에 있는 노드의 높이 중 최댓값

// 트리 - 정의와 속성
// 트리 (Tree)
// - 비순환 연결 그래프
// - 속성
// 1. 임의의 두 정점 사이의 단순 경로 유일
// 2. (간선의 수) = (정점의 수) - 1
// 3. 순환하는 경로가 없음
// (위 3가지 중 하나만 만족해도 서로 만족함)

// 트리 - 특징
// 트리 (Tree)
// - 특징
// 1. 트리는 하나의 루트노드를 가진다
// 2. 루트노드는 0개 이상의 자식노드를 가진다
// 3. 그 자식노드도 0개 이상의 자식노드를 가지고, 이는 반복적으로 정의된다

// 이진트리 - 정의와 속성
// 이진트리 (Binary Tree)
// - 각각의 노드가 최대 2개의 자식 노드를 갖는 트리
// - 왼쪽 & 오른쪽 서브트리 모두 이진트리
// - 높이가 h-1인 이진트리의 노드 수는 h ~ 2^h - 1
// (최소 : 편향, 최대 : 포화)

// 이진트리 - 종류
// 편향 이진트리 (Skewed Binary Tree)
// - 모든 노드가 하나의 차수로만 이루어져 있는 이진트리
// - 노드 수 : h개 (트리의 높이 h - 1)
// - 노드 탐색할 때 걸리는 시간 : O(N)
// 완전 이진트리 (Complete Binary Tree)
// - 마지막 레벨을 제외하고 모든 레벨이 채워져 있으며,
// 마지막 레벨은 왼쪽부터 채워진 이진트리
// - 힙에 사용되는 자료구조
// 포화 이진트리 (Perfect Binary Tree)
// - 리프 노드를 제외하고 모든 노드의 차수가 2개로 이루어져 있는 이진트리
// - 노드 수 : 2^h - 1개 (트리의 높이 h - 1)
// - 노드 수 파악하기 쉬움

// 힙 - 정의
// 힙 (Heap)
// - 최댓값 or 최솟값을 빠르게 찾기 위해 고안된 완전 이진트리
// (최대힙 or 최소힙)
// - 각 노드에 키(key) & 요소(element) 저장
// - 주로 이진 힙 사용

// 힙 - 속성
// - A가 B의 부모 노드면 A의 키(key)값과 B의 키값 사이에 대소관계 성립
// - 최대힙 : key(T.parent(v)) > key(v) (최댓값)
// - 최소힙 : key(T.parent(v)) < key(v) (최솟값)
// - 가장 높은 or 낮은 우선순위를 갖는 노드가 항상 뿌리노드에 옴
// -> 우선순위 큐 구현할 때 사용

// 힙 - 구현
// 힙 (Heap)
// 배열로 구현
// i번재 노드의...
// - 왼쪽 자식 2i
// - 오른쪽 자식 2i + 1
// - 부모 i/2

// 힙 - 삽입
// - 힙에 원소 삽입하기
// 1. 우선 마지막 노드에 연결
// 2. 부모노드와 계속 비교하면서 swap

// 힙 - 삭제
// - 힙에서 원소 삭제하기
// 1. 루트노드 삭제
// 2. 가장 마지막 노드 -> 루트노드
// 3. 자식 노드와 계속 비교하면서 swap
// a. 최대힙 : 더 큰 값과 swap
// b. 최소힙 : 더 작은 값과 swap

// 힙 - 시간복잡도
// 힙의 시간복잡도
// - 트리의 높이 : O(logN)
// - 삽입 : O(logN)
// - 삭제 : O(logN)
// - 접근 : O(1) (배열 접근과 동일)

// 이진탐색트리 - 정의와 속성
// 이진탐색트리 (Binary Search Tree, BST)
// 다음과 같은 속성이 있는 이진트리 자료구조
// - 모든 노드에 값이 있음
// - 값들은 전순서가 있음 ( = 비교 가능, 중복 X)
// - 모든 왼쪽 자식들 <= i <= 모든 오른쪽 자식들
// left subtree < root < right subtree
// (모든 노드 i에 대해서 반드시 true)
// - 좌우 서브트리는 다시 BST

// 이진탐색트리 - 탐색 과정
// 이진탐색트리 (Binary Search Tree, BST)
// 탐색 과정
// - 트리에 찾고자 하는 값의 노드 존재하면 해당 노드 리턴 (없으면 NULL)
// 1. 찾고자 하는 값과 루트노드 비교
// 2. 찾고자 하는 값이 루트노드보다...
// a. 작으면 왼쪽 서브트리로 이동
// b. 크면 오른쪽 서브트리로 이동
// 이분탐색과 유사 O(logN)

// 이진탐색트리 - 시간복잡도
// 이진탐색트리 (Binary Search Tree, BST)
// - 원소 넣는 순서에 따라 높이 달라짐
// - 최악 : O(N)
// - 평균 : O(logN)
// - 자가 균형 BST : Red-Black Tree, AVL Tree, Splay Tree

// 이진탐색트리 - STL
// 이진탐색트리 (Binary Search Tree, BST)
// - C++ STL에도 BST 존재 !
// - std::set, std::map
// - Red-Black Tree 기반 (자가 균형 BST)
// - 탐색/삽입/삭제 평균 O(logN)

// 트리 순회
// 그래프 탐색 - DFS
// 깊이 우선 탐색 (Depth-First Search)
// - 깊이가 깊어지는 방향으로 그래프를 탐색하는 알고리즘
// 트리 순회 (Tree Traversal)
// 일반 트리에서의 순회
// - 그래프 순회하듯이 DFS
// - 결국 트리도 그래프의 일종
// 주로 이진 트리에서의 순회를 뜻함 (전위, 중위, 후위)

// 트리 순회 - 전위
// 전위 순회 (Preorder)
// - 루트 -> 왼쪽 -> 오른쪽 ("V"LR)
// - 깊이 우선 순회 (Depth-First Traversal, DFS)
/*
void preorder(Node* curr) {
	if (curr != null) {
		cout << curr -> data << ' ';
		preorder(curr -> left);
		preorder(curr -> right);
	}
}
*/

// 트리 순회 - 중위
// 중위 순회 (Inorder)
// - 왼쪽 -> 루트 -> 오른쪽 (L"V"R)
// - 대칭 순회 (symmetric traversal)
// - BST에서 오름/내림차순으로 값 가져올 때 사용 (내림차순은 역순, RVL)
/*
void inorder(Node* curr) {
	if (curr != null) {
		inorder(curr -> left);
		cout << curr -> data << ' ';
		inorder(curr -> right);
	}
}
*/

// 트리 순회 - 후위
// 후위 순회 (Postorder)
// - 왼쪽 -> 오른쪽 -> 루트 (LR"V")
// - 트리에서 원소 삭제할 때 사용
// (부모노드 삭제하기 전에 자식노드 먼저 삭제)
/*
void postorder(Node* curr) {
	if (curr != null) {
		postorder(curr -> left);
		postorder(curr -> right);
		cout << curr -> data << ' ';
*/

// 트리 순회
// 순회 응용
// - 전위("V"LR) : functional form
// div(Add(A, B), sub(C, D))
// - 중위(L"V"R) : 인간에게 익숙한 형식
// (A + B) / (C - D)
// - 후위(LR"V") : stack machine, 후위표기법
// AB + CD-/

// 트리 - 응용
// 트리의 지름 (Diameter of tree)
// - 트리의 모든 경로들 중 가장 긴 경로의 길이
// - 구하는 과정
// 1. 트리에서 임의의 정점 x를 잡는다
// 2. 정점 x에서 가장 먼 정점 a를 찾는다 (DFS 1번)
// 3. 정점 a에서 가장 먼 정점 b를 찾는다 (DFS 2번)
// -> DFS 2번만에 트리의 지름 구할 수 있음!
// 트리 정리
// 트리
// - 비순환 연결 그래프
// - 임의의 두 정점 사이의 단순 경로 유일
// - (간선의 수) = (정점의 수) - 1
// 이진트리
// - 자식노드 최대 2개
// - 높이 h-1 -> 노드 수 h ~ 2^h - 1
// 힙 (최대힙)
// - key(T.parent(v)) > key(v)
// - 가장 큰 값이 루트노드에 -> 우선순위 큐
// BST
// - 왼쪽 <= i <= 오른쪽
// - O(logN)
// - std::set, std::map
// 트리순회
// - 전위(pre) "V"LR
// - 중위(in) L"V"R
// - 후위(post) LR"V"
// 트리지름
// - DFS 2번 !!



pair<char, char> tree[26];

// 전위 순회한 결과 : (루트) (왼쪽 자식) (오른쪽 자식)
void preorder(char node) {
	// 자식 노드가 없는 경우에는 .으로 표현한다.
	if (node == '.') {
		return;
	}
	// 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
	else {
		// (루트)
		cout << node;

		// (왼쪽 자식)
		preorder(tree[node - 'A'].first);

		// (오른쪽 자식)
		preorder(tree[node - 'A'].second);
	}
}

// 중위 순회한 결과 : (왼쪽 자식) (루트) (오른쪽 자식)
void inorder(char node) {
	// 자식 노드가 없는 경우에는 .으로 표현한다.
	if (node == '.') {
		return;
	}
	// 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
	else {
		// (왼쪽 자식)
		inorder(tree[node - 'A'].first);

		// (루트) 
		cout << node;

		// (오른쪽 자식)
		inorder(tree[node - 'A'].second);
	}
}

// 후위 순회한 결과 : (왼쪽 자식) (오른쪽 자식) (루트)
void postorder(char node) {
	// 자식 노드가 없는 경우에는 .으로 표현한다.
	if (node == '.') {
		return;
	}
	// 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
	else {
		// (왼쪽 자식)
		postorder(tree[node - 'A'].first);

		// (오른쪽 자식) 
		postorder(tree[node - 'A'].second);

		// (루트)
		cout << node;
	}
}

int main() {
	int n;
	char parent, leftchild, rightchild;

	// 첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다.
	cin >> n;

	// 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
	for (int i = 0; i < n; i++) {
		cin >> parent >> leftchild >> rightchild;

		tree[parent - 'A'].first = leftchild;
		tree[parent - 'A'].second = rightchild;
	}

	// 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며,
	// 항상 A가 루트 노드가 된다. 
	// 첫째 줄에 전위 순회,
	preorder('A');
	cout << '\n';

	//  둘째 줄에 중위 순회, 
	inorder('A');
	cout << '\n';

	// 셋째 줄에 후위 순회한 결과를 출력한다.
	postorder('A');

	return 0;
}