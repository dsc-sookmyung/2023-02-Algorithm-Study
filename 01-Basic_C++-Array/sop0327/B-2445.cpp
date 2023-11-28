#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        for (int j = 1; j <= num - i; j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        cout << "\n";
    }

    for (int i = num - 1; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }

        for (int j = 1; j <= num - i; j++)
        {
            cout << "  ";
        }

        for (int j = i; j > 0; j--)
        {
            cout << "*";
        }

        cout << "\n";
    }

    return 0;
}
