#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num, a, b, sum;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> a >> b;
        sum = a + b;
        cout << sum << "\n";
    }

    return 0;
}