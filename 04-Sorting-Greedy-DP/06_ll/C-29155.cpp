#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> level(5); // 난이도별 풀 문제 수
    for (int i = 0; i < 5; ++i) {
        cin >> level[i];
    }

    vector<pair<int, int>> exam;
    for (int i = 0; i < N; ++i) {
        int k, t;
        cin >> k >> t;
        exam.push_back({ k, t });
    }

    sort(exam.begin(), exam.end());

    int res = 0;
    int before_level = 1;
    int before_time = 0;
    bool first_clear = true;

    for (auto [i, j] : exam) {
        if (level[i - 1] > 0) {
            res += j;
            level[i - 1] -= 1;

            if (first_clear) {
                first_clear = false;
            }
            else if (before_level == i) {
                res += (j - before_time);
            }
            else if (before_level != i) {
                res += 60;
            }

            before_level = i;
            before_time = j;
        }
    }

    cout << res << endl;

    return 0;
}
