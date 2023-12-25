#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> hw;
    vector<bool> visit(1001, false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int day, score;
        cin >> day >> score;
        hw.push_back(make_pair(day, score));
    }

    sort(hw.begin(), hw.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second > b.second; });

    int ans = 0;

    for (const auto &p : hw)
    {
        int i = p.first;

        while (i > 0 && visit[i])
        {
            i -= 1;
        }

        if (i == 0)
        {
            continue;
        }
        else
        {
            visit[i] = true;
            ans += p.second;
        }
    }

    cout << ans << endl;

    return 0;
}