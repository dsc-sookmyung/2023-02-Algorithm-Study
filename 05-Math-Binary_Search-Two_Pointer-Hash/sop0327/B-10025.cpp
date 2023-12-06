#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> arr(1000001, 0); // 벡터를 사용하여 배열 선언 및 초기화

    for (int i = 0; i < N; i++)
    {
        int g, x;
        cin >> g >> x;
        arr[x] = g;
    }

    K = 2 * K + 1;
    int sum = 0;
    int ans = 0; // 초기화 추가
    for (int i = 0; i <= 1000001; i++)
    {
        if (i >= K)
        {
            sum -= arr[i - K];
        }
        sum += arr[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}