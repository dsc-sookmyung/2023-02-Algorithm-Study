#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int K;
vector<int> arr;
int result = INT_MAX;

void binarySearch(int low, int high);

int check(int H) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            int me = arr[i];
            int after = arr[i + 1];

            if (abs(me - after) > H) {
                count++;
            }
        }
        else {
            int before = arr[i - 1];
            int me = arr[i];
            int after = arr[i + 1];

            if (abs(me - before) > H || abs(me - after) > H) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    arr.resize(N + 1);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    arr[N] = arr[N - 1];

    binarySearch(0, INT_MAX);

    cout << result << endl;

    return 0;
}

void binarySearch(int low, int high) {
    if (low > high) {
        return;
    }

    int mid = low + (high - low) / 2;
    int count = check(mid);

    if (K < count) {
        binarySearch(mid + 1, high);
    }
    else {
        result = min(result, mid);
        binarySearch(low, mid - 1);
    }
}
