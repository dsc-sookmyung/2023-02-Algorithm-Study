#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string str;
        cin >> str;
        stack<char> arr;
        int temp = 0;

        for (int j = 0; j < str.size(); j++)
        {

            if (str[j] == '(')
            {
                arr.push('(');
            }
            else if (str[j] == ')')
            {
                if (!arr.empty() && arr.top() == '(')
                {
                    arr.pop();
                }
                else
                {
                    cout << "NO"
                         << "\n";
                    temp = 1;
                    break;
                }
            }
        }

        if (temp == 0 && arr.empty())
        {
            cout << "YES"
                 << "\n";
        }
        else if (temp == 0 && !arr.empty())
        {
            cout << "NO"
                 << "\n";
        }
    }

    return 0;
}