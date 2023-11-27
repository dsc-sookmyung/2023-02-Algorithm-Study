#include <iostream>
#include <algorithm>

// sort 함수는 함수를 지정해 함수의 결과에 따라 정렬할 수 있다

using namespace std;

bool new_sort(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    else
        return a < b;
}

int main()
{
    int n;
    cin >> n;
    string words[20000];

    for (int i = 0; i < n; i++)
        cin >> words[i];

    sort(words, words + n, new_sort);

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << words[i] << '\n';
        else if (i != 0 && words[i] != words[i - 1])
            cout << words[i] << '\n';
    }

    return 0;
}