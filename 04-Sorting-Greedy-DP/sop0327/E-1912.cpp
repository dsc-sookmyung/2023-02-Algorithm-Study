#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int numbers[100009];
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int maxSum = -1001;
    int dp[100009];

    for (int i = 0; i < n; i++)
    {
        if (dp[i - 1] + numbers[i] < numbers[i])
            dp[i] = numbers[i];
        else
            dp[i] = dp[i - 1] + numbers[i];

        if (dp[i] >= maxSum)
            maxSum = dp[i];
    }

    cout << maxSum;

    return 0;
}