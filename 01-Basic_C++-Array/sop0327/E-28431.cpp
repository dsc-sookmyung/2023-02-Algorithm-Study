#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e;
    int arr[10] = {0};

    cin >> a >> b >> c >> d >> e;
    arr[a]++;
    arr[b]++;
    arr[c]++;
    arr[d]++;
    arr[e]++;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] != 0 && arr[i] % 2 == 1)
            cout << i;
    }

    return 0;
}