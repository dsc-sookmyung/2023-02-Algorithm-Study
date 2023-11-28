#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include <array>
using namespace std;

int main() {
    int A, B, C, num;
    cin >> A;
    cin >> B;
    cin >> C;
    num = A * B * C;

    std::vector<int> a; 

    while (num != 0) {
        int digit = num % 10; 
        a.push_back(digit);  
        num /= 10;          
    }

    std::array<int, 10> count = {0};

    for (int digit : a) {
        count[digit]++;
    }

    for (int i = 0; i <= 9; i++) {
        cout << count[i] << endl;
    }

    return 0;
}





