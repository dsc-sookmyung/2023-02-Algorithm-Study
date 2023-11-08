#include <iostream>
using namespace std;

int main() {
	// 아래 얘기는 cin, cout을 쓸 때의 얘기지, scanf/prinf로 입출력을 하고자 하신다면 그냥 쓰시면 됩니다. scanf/printf는 충분히 빠릅니다.
	
	// endl은 개행문자를 출력할 뿐만 아니라 출력 버퍼를 비우는 역할까지 합니다. 
	// 그래서 출력한 뒤 화면에 바로 보이게 할 수 있는데, 그 버퍼를 비우는 작업이 매우 느립니다. 
	// 게다가 온라인 저지에서는 화면에 바로 보여지는 것은 중요하지 않고 무엇이 출력되는가가 중요하기 때문에 버퍼를 그렇게 자주 비울 필요가 없습니다.
	// 그래서 endl을 '\n'으로 바꾸는 것만으로도 굉장한 시간 향상이 나타납니다.
	
	// cin.tie(NULL)은 cin과 cout의 묶음을 풀어 줍니다.
	// 기본적으로 cin으로 읽을 때 먼저 출력 버퍼를 비우는데, 마찬가지로 온라인 저지에서는 화면에 바로 보여지는 것이 중요하지 않습니다. 
	// 입력과 출력을 여러 번 번갈아서 반복해야 하는 경우 필수적입니다.

	// ios_base::sync_with_stdio(false)는 C와 C++의 버퍼를 분리합니다. 
	// 이것을 사용하면 cin/cout이 더 이상 stdin/stdout과 맞춰 줄 필요가 없으므로 속도가 빨라집니다. 
	// 단, 버퍼가 분리되었으므로 cin과 scanf, gets, getchar 등을 같이 사용하면 안 되고, cout과 printf, puts, putchar 등을 같이 사용하면 안 됩니다.
	


	// 본격적으로 for문 문제를 풀기 전에 주의해야 할 점이 있다.
	// 입출력 방식이 느리면 여러 줄을 입력받거나 출력할 때 시간초과가 날 수 있다는 점이다.
	// C++을 사용하고 있고 cin/cout을 사용하고자 한다면,
	// cin.tie(NULL)과 sync_with_stdio(false)를 둘 다 적용해 주고,
	// endl 대신 개행문자(\n)를 쓰자.
	// 단, 이렇게 하면 더 이상 scanf/printf/puts/getchar/putchar 등 C의 입출력 방식을 사용하면 안 된다.
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// T는 최대 1,000,000이다.
	// A와 B는 1 이상, 1,000 이하이다.
	int t, a, b;

	// 첫 줄에 테스트케이스의 개수 T가 주어진다.
	cin >> t;

	// 입력과 출력 스트림은 별개이므로,
	// 테스트케이스를 전부 입력받아서 저장한 뒤 전부 출력할 필요는 없다.
	// 테스트케이스를 하나 받은 뒤 하나 출력해도 된다.
	for (int i = 0; i < t; i++) {
		// 다음 T줄에는 각각 두 정수 A와 B가 주어진다. 
		cin >> a >> b;
		// 각 테스트케이스마다 A+B를 한 줄에 하나씩 순서대로 출력한다.
		cout << a + b << '\n';
	}

	return 0;
}