#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> zoo(N, vector<int>(2));

    int maxIndex = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> zoo[i][j];
            if (j == 1) {
                maxIndex = max(maxIndex, zoo[i][j]);
            }
        }
    }

    vector<int> arr(maxIndex + 1, 0);

    for (int i = 0; i < N; ++i) {
        arr[zoo[i][1]] = zoo[i][0];
    }

    int step = K * 2 + 1;
    int tmp = 0;

    for (int i = 0; i < step && i <= maxIndex; ++i) {
        tmp += arr[i];
    }

    int result = tmp;

    for (int i = step; i <= maxIndex; ++i) {
        tmp += arr[i] - arr[i - step];
        result = max(result, tmp);
    }

    cout << result << endl;

    return 0;
}