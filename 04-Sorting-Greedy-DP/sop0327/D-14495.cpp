#include <iostream>

using namespace std;

int main()
{
    int n;
    long long numbers[116] = {1, 1, 1};
    cin >> n;

    for (int i = 3; i < n; i++)
        numbers[i] = numbers[i - 1] + numbers[i - 3];

    cout << numbers[n - 1];

    return 0;
}