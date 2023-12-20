#include <iostream>
#include <unordered_set>
#include <sstream>

using namespace std;

int main()
{
    int toppingCount;
    cin >> toppingCount;
    cin.ignore(); // 버퍼 비우기

    unordered_set<string> toppings;

    string toppingList;
    getline(cin, toppingList);

    stringstream ss(toppingList);
    string topping;

    while (ss >> topping)
    {
        toppings.insert(topping);
    }

    // "Cheese"로 끝나는 토핑 중 최소 4개가 필요
    int cheeseCount = 0;
    for (const auto &t : toppings)
    {
        if (t.length() >= 6 && t.substr(t.length() - 6) == "Cheese")
        {
            cheeseCount++;
        }
    }

    if (cheeseCount >= 4)
    {
        cout << "yummy\n";
    }
    else
    {
        cout << "sad\n";
    }

    return 0;
}