#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 에라토스테네스의 체를 사용하여 소수 판별
void sieve(vector<bool> &isPrime, int limit)
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(limit); ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int countPrimes(int n)
{
    vector<bool> isPrime(2 * n + 1, true);

    sieve(isPrime, 2 * n);

    int count = 0;
    for (int i = n + 1; i <= 2 * n; ++i)
    {
        if (isPrime[i])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            break;
        }

        int result = countPrimes(n);
        cout << result << endl;
    }

    return 0;
}