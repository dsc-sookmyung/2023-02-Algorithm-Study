#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 정렬 - 정의
// - 정렬
// 데이터를 특정한 조건에 따라 일정한 순서가 되도록 다시 배열하는 일
// -> 정렬되어 있으면 자료를 쉽게 찾을 수 있음!

// 정렬 - 정렬 알고리즘
// - 안정 정렬
// 정렬을 했을 때, 같은 값들은 정렬하기 전의 상대적 위치를 유지하는 정렬
// -> 버블 정렬 (Bubble Sort)
// -> 삽입 정렬 (Insertion Sort)
// -> 합병 정렬 (Merge Sort)
// 
// - 버블 정렬 (Bubble Sort)
// 1. 인접한 두 수를 선택한 뒤, 만약 그 두 수가 정렬되었다면 놔두고 아니라면 두 수를 바꾼다.
// 2. 1.을 배열의 처음부터 끝까지 반복한다.
// 3. 위 알고리즘을 배열에 아무 변화가 없을 때까지 반복한다.
// -> 매번 반복할 때마다 가장 큰 수가 제일 뒤로 간다!
// -> 시간 복잡도 : 최선 O(N), 평균 O(N^2), 최악 O(N^2)
/*
void bubbleSort(int arr[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++) {
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
*/
//
// - 삽입 정렬 (Insertion Sort)
// 1. k번째 원소를 앞의 원소들과 역순으로 비교하며,
// 처음으로 등장하는 k번째 원소보다 크지 않은 원소 뒤에 위치시킨다.
// 2. 1.을 배열의 처음부터 끝까지 반복한다.
// 3. 위 알고리즘을 배열에 아무 변화가 없을 때까지 반복한다.
// -> 매번 반복할 때마다 앞의 배열이 정렬된다!
// -> 시간 복잡도 : 최선 O(N), 평균 O(N^2), 최악 O(N^2)
/*
void insertionSort(int arr[], int n) {
	int i, key, j;

	for (i = 1; i < n; i++) {
		// 앞의 원소들과 역순 비교할 원소
		key = arr[i];
		j = i - 1;

		// 앞의 원소가 key보다 크면 swap
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}
*/
//
// - 합병 정렬 (Merge Sort)
// 1. 정렬되지 않은 배열의 크기가 1이 될 때까지 절반으로 잘라 나눈다.
// 2. 인접한 두 개의 배열을 정렬하면서 합친다.
// 3. 위 알고리즘을 배열이 모두 합쳐질 때까지 반복한다.
// -> 시간 복잡도 : 최선 O(NlogN), 평균 O(NlogN), 최악O(NlogN)
/*
void merge (int arr[], int l, int m, int r) {
	// 각각 arr의 왼쪽, arr의 중간, tmp의 왼쪽
	int idx1, idx2, idx3;
	idx1 = idx3 = l;
	idx2 = m;

	while (idx1 < m && idx2 < r) {
		if (arr[idx1] < arr[idx2]) {
			tmp[idx3++] = arr[idx1++];
		}
		else {
			tmp[idx3++] = arr[idx2++];
		}
	}

	while (idx1 < m) {
		tmp[idx3++] = arr[idx1++];
	}
	while (idx2 < r) {
		tmp[idx3++] = arr[idx2++];
	}

	for (int i = l; i < r; i++) {
		arr[i] = tmp[i];
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l == r - 1) {
		return;
	}

	int m = (l + r) / 2;

	mergeSort(arr, l, m);
	mergeSort(arr, m, r);
	merge(arr, l, m, r);
}
*/
// 리스트의 길이가 1 이하이면 이미 정렬된 것으로 본다.
// 그렇지 않은 경우에는
// 1. 분할(divide)
// : 정렬되지 않은 리스트를 절반으로 잘라 비슷한 크기의 두 부분 리스트로 나눈다.
// 2. 정복(conquer)
// : 각 부분 리스트를 재귀적으로 합병 정렬을 이용해 정렬한다.
// 3. 결합(combine)
// : 두 부분 리스트를 다시 하나의 정렬된 리스트로 합병한다.
// 이때 정렬 결과가 임시배열에 저장된다.
// 4. 복사(copy)
// : 임시 배열에 저장된 결과를 원래 배열에 복사한다.
// 
// - 불안정 정렬
// 정렬을 했을 때, 같은 값들이 정렬하기 전의 상대적 위치와 달라질 수도 있는 정렬
// -> 퀵 정렬 (Quick Sort)
// -> 선택 정렬 (Selection Sort)
// -> 힙 정렬 (Heap Sort)
//
// - 퀵 정렬 (Quick Sort)
// 1. 임의의 index를 pivot으로 잡는다.
// 2. 피벗 좌측에는 피벗보다 작은 수, 우측에는 큰 수가 오게끔 배치한다.
// 3. 피벗을 제외한 피벗의 좌측과 우측 두 개의 리스트에 대해서 위 과정을 재귀적으로 반복한다.
// -> 시간 복잡도 : 최선 O(NlogN), 평균 O(NlogN), 최악 O(N^2)
// 
// - 선택 정렬 (Selection Sort)
// 1. 정렬되지 않은 배열의 최솟값을 선택한다.
// 2. 그 최솟값을 배열의 맨 앞의 값과 바꾼다.
// 3. 최솟값이 저장된 index의 다음부터 위 과정을 반복한다.
// -> 시간 복잡도 : 최선 O(N^2), 평균 O(N^2), 최악 O(N^2)
/*
void selectionSort(int arr[], int n) {
	int temp, min_idx;

	for(int i = 0; i < n - 1; i++) {
		min_idx = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}
*/
//
// - 힙 정렬 (Heap Sort)
// 1. 정렬해야 할 n개의 원소들로 최대/최소 힙을 만든다.
// 2. 한 번에 하나씩 원소를 힙에서 꺼내서 배열의 뒤부터 저장한다.
// 3. 2.를 원소가 모두 꺼내질 때까지 반복한다.
// -> 시간 복잡도 : 최선 O(NlogN), 평균 O(NlogN), 최악 O(NlogN)
//
// 정렬 알고리즘 정리
// - 같은 문제를 푸는 다양한 방법이 존재
// - 현재 상황에 맞는 효율적인 방법을 선택하자

// 정렬 - std::sort
// - C++의 sort 함수 std::sort(start, end)
// algorithm 헤더의 std::sort 함수를 사용할 수 있음
// -> 사용 방법 : std::sort(start, end);
// -> [start, end)를 data type의 오름차순으로 정렬해줌
// -> 시간 복잡도 : O(NlogN)
/*
#include <algorithm>

std::sort(arr, arr+n);
*/
// - C++의 sort 함수는 어떤 정렬 알고리즘을 사용하는 걸까?
// Intro sort(Insertion + Quick + Heap sort)
// -> stable이 보장되지 않음
/*
if n <= 16
	Insertion sort;
else
	Quick sort;
	하지만 만약 재귀 깊이가 2*log n보다 크고 해당 영역이 16 초과라면 Heap sort
*/
// Stable sort
// : Merge Sort 이용
/*
#include <algorithm>

std::stable_sort(arr, arr + n);
*/
// - 내림차순 정렬하기
// 1) 오름차순으로 정렬하고 반대로 출력하기
// 2) 부호 뒤집어 입력 받고 오름차순 정렬 후 부호 뒤집어 출력하기
// 3) reverse 함수를 이용해서 오름차순 정렬 후 뒤집기
/*
sort(arr, arr + n);
reverse(arr, arr + n);
*/
/*
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
*/
// 4) 시작 위치와 끝 위치를 반대로 정렬하기
/*
sort(v.rbegin(), v.rend());
*/
// 5) 비교함수를 이용해서 내림차순 정렬하기
// - 비교함수 이용해서 내림차순 정렬하기
// -> 사용 방법 : std::sort(start, end, compare);
// -> compare 함수를 정의하여 원하는 순서로 정렬할 수 있음
/*
#include <algorithm>

bool compare (int a, int b) {
	return a > b;
}

std::sort(arr, arr + n, compare);
*/
// - 비교함수 이용해서 원하는 순서로 정렬하기
// 1) 구조체 원소로 '가입한 순서'도 추가하기
/*
struct member {
	string name;
	int age, index;
};

bool compare (const member &a, const member &b) {
	if (a.age != b.age) {
		return a.age < b.age;
	}
	else {
		return a.index < b.index;
	}
}
*/
// 2) stable_sort 함수 사용하기



// 알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성
int cmp(string a, string b) {
	// 2. 길이가 같으면 사전 순으로
	if (a.length() == b.length()) {
		return a < b;
	}
	// 1. 길이가 짧은 것부터
	else {
		return a.length() < b.length();
	}
}

// 변수의 범위가 크면 전역 변수로 설정

int main() {
	// (1 ≤ N ≤ 20,000) 
	int n;
	vector<string> word;

	// 첫째 줄에 단어의 개수 N이 주어진다. 
	cin >> n;

	// 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 
	// 주어지는 문자열의 길이는 50을 넘지 않는다.
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		// 단, 중복된 단어는 하나만 남기고 제거해야 한다.
		if (find(word.begin(), word.end(), str) == word.end()) {
			word.push_back(str);
		}
	}

	// 조건에 따라 정렬하여 단어들을 출력한다.
	sort(word.begin(), word.end(), cmp);

	// vector 쓸 때는 i < n 말고 i < word.size() 사용해야 함
	for (int i = 0; i < word.size(); i++) {
		cout << word[i] << '\n';
	}

	return 0;
}