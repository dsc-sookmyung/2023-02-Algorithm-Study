#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int numT;
	cin >> numT;


	for (int i = 0; i < numT; i++) {
		stack<char> st;
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			if (st.empty() || s[j] == '(') st.push(s[j]);
			else if (st.top() == '(') st.pop();
		}

		if (st.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}