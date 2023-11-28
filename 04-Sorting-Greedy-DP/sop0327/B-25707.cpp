#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int numbers[1000];
    int n, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    sort(numbers, numbers + n);

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            sum += abs(numbers[i] - numbers[i + 1]);
        else
            sum += abs(numbers[i] - numbers[0]);
    }

    cout << sum;

    return 0;
}