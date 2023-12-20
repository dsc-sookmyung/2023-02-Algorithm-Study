#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;
vector<int> arr;
int result = INT_MAX;

int check(int H)
{
    // 지친 사람이 몇 명인지 검사
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            int me = arr[i];
            int after = arr[i + 1];

            if (abs(me - after) > H)
            {
                count++;
            }
        }
        else
        {
            int before = arr[i - 1];
            int me = arr[i];
            int after = arr[i + 1];

            if (abs(me - before) > H || abs(me - after) > H)
            {
                count++;
            }
        }
    }

    return count;
}

void binarySearch(int low, int high)
{
    if (low > high)
    {
        return;
    }

    int mid = (low + high) / 2;
    int count = check(mid);

    // 지친 사람이 K명 이하 일 경우 더 줄 일 수 있음 -> 높이 (mid)를 낮추기
    if (K < count)
    {
        binarySearch(mid + 1, high);
    }
    else
    {
        // 기존의 인원 수 보다 클 경우
        result = min(result, mid);
        binarySearch(low, mid - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    arr.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    arr[N] = arr[N - 1];

    binarySearch(0, INT_MAX);

    cout << result << endl;

    return 0;
}