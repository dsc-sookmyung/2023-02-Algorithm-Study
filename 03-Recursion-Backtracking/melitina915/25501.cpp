#include <iostream>
#include <cstring>
using namespace std;

int cnt;

int recursion(const char* s, int l, int r) {
    cnt++;

    if (l >= r) {
        return 1;
    }
    else if (s[l] != s[r]) {
        return 0;
    }
    else {
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    //printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
    //printf("ABC: %d\n", isPalindrome("ABC"));   // 0

    // (1 <= T <= 1,000)
    int t;
    // (1 <= |S| <= 1,000)
    char s[1001];

    // 첫째 줄에 테스트케이스의 개수 T가 주어진다.
    cin >> t;

    // 둘째 줄부터 T개의 줄에 알파벳 대문자로 구성된 문자열 S가 주어진다.
    for (int i = 0; i < t; i++) {
        cin >> s;

        // 각 테스트케이스마다,
        // isPalindrome 함수의 반환값과 recursion 함수의 호출 횟수를 한 줄에 공백으로 구분하여 출력한다.
        // isPalindrome 함수와 cnt를 한 줄에 출력하도록 작성할 경우 cnt 업데이트가 제대로 안된다고 한다.
        // 따라서 isPalindrome과 cnt를 두 줄로 나눠 출력한다
        cout << isPalindrome(s);
        cout << ' ' << cnt << '\n';

        cnt = 0;
    }
}