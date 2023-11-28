#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, temp;
    queue<int> arr;

    cin >> num;
    for (int i = 1; i <= num; i++)
        arr.push(i);

    while (arr.size() != 1)
    {
        arr.pop();
        temp = arr.front();
        arr.pop();
        arr.push(temp);
    }

    cout << arr.front();

    return 0;
}