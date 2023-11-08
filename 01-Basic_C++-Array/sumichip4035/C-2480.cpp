#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A == B && B == C) {
        cout << (10000 + A * 1000);
    } else if (A == B || B == C || A == C) {
        int sameValue;
        if (A == B) sameValue = A;
        else if (B == C) sameValue = B;
        else sameValue = C;
        cout << (1000 + sameValue * 100);
    } else {
        int maxVal = max(A, max(B, C));
        cout << (maxVal * 100);
    }
    
    return 0;
}
