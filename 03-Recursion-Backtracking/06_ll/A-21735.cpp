#include <iostream>
using namespace std;
int n, m, a[101];

int func(int i, int cnt, int size) {
    if (cnt > m) return 0;
    if (cnt == m) return size;
    int ans = 0;
    ans = max(func(i + 1, cnt + 1, size + a[i + 1]), func(i + 2, cnt + 1, size / 2 + a[i + 2]));
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << func(0, 0, 1);
}