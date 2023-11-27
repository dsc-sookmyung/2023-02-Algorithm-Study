#include <iostream>
long long fb[117] = { 0,1,1,1 };
int main() {
    int n;
    std::cin >> n;
    for (int i = 3; i <= n; i++)fb[i] = fb[i - 1] + fb[i - 3];
    std::cout << fb[n];
}
