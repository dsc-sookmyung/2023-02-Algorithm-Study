#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;

    vector<int> lan_lengths(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> lan_lengths[i];
    }

    // 랜선 길이 정렬
    sort(lan_lengths.begin(), lan_lengths.end());

    // 이분 탐색을 통해 최대 길이 찾기
    long long left = 1, right = lan_lengths.back();
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        int count = 0;

        for (int i = 0; i < K; ++i)
        {
            count += lan_lengths[i] / mid;
        }

        if (count >= N)
        {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << endl;

    return 0;
}
