#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num1, num2;
    char al;
    cin >> num1;
    deque<char> arr1;
    deque<int> arr2;

    for (int i = 1; i <= num1; i++)
    {
        cin >> num2;

        if (num2 == 1)
        {
            cin >> al;
            arr1.push_back(al);
            arr2.push_back(1);
        }
        else if (num2 == 2)
        {
            cin >> al;
            arr1.push_front(al);
            arr2.push_back(2);
        }
        else if (!arr1.empty())
        {
            if (arr2.back() == 1)
            {
                arr1.pop_back();
                arr2.pop_back();
            }
            else
            {
                arr1.pop_front();
                arr2.pop_back();
            }
        }
    }

    if (arr1.empty())
    {
        cout << 0;
    }
    else
    {
        while (!arr1.empty())
        {
            cout << arr1.front();
            arr1.pop_front();
        }
    }

    return 0;
}