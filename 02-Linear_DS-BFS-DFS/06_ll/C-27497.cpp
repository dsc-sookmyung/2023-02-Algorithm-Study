#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <deque>
#include <algorithm>

using namespace std;


int main() {
    int N, M;
    char C;
    stack<bool> S;
    deque<char> dQ;

    cin >> N;

    while (N--) {
        cin >> M;
        if (M == 1) {
            cin >> C;
            dQ.push_back(C);
            S.push(false);
        }
        else if (M == 2) {
            cin >> C;
            dQ.push_front(C);
            S.push(true);
        }
        else if (M == 3) {
            if (S.empty()) {
                continue;
            }

            if (S.top()) {
                dQ.pop_front();
            }
            else {
                dQ.pop_back();
            }

            S.pop();
        }
    };

    if (dQ.empty()) {
        cout << "0\n";
    }
    else {
        while (!dQ.empty()) {
            cout << dQ.front();
            dQ.pop_front();
        };
        cout << "\n";
    }
    return 0;
}