#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> tree(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tree[i];
    }

    int remove;
    cin >> remove;

    function<void(int)> deleteNode = [&](int node)
    {
        tree[node] = -2;
        for (int i = 0; i < n; ++i)
        {
            if (tree[i] == node)
            {
                tree[i] = -2;
                deleteNode(i);
            }
        }
    };

    deleteNode(remove);

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (tree[i] != -2 && find(tree.begin(), tree.end(), i) == tree.end())
        {
            cnt += 1;
        }
    }

    cout << cnt << endl;

    return 0;
}