#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
vector<int> v;
vector<int> ans;

void n_m(int num)
{
    if (num == m) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        ans.push_back(v[i]);
        n_m(num + 1);
        ans.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    n_m(0);
    return 0;
}
