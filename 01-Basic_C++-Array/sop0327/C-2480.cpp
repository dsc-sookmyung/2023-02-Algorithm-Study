#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, reward;
    cin >> a >> b >> c;

    if ((a == b) && (b == c))
    {
        reward = 10000 + a * 1000;
    }
    else if (a == b || b == c || c == a)
    {
        int matching = (a == b) ? a : ((b == c) ? b : c);
        reward = 1000 + matching * 100;
    }
    else
    {
        reward = max(max(a, b), c) * 100;
    }

    cout << reward;

    return 0;
}