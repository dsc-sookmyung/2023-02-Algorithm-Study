#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_SIZE 1025

using namespace std;

int N, re_N;
int falling[MAX_SIZE][MAX_SIZE];
queue<int> q;

bool compare(int a, int b) {
    if (a > b) return true;
    else return false;
}

void submatrix(int x, int y) {
    vector<int> v;
    for (int i = x; i < x + 2; i++) {
        for (int j = y; j < y + 2; j++) {
            v.push_back(falling[i][j]);
        }
    }
    sort(v.begin(), v.end(), compare);
    q.push(v.at(1));
    v.clear();
}

void fallingDown(int size, int x, int y) {
    int n = size / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            submatrix(x + i * 2, y + j * 2);
        }
    }
    re_N = n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> falling[i][j];
    re_N = N;

    while (1) {
        fallingDown(N,0,0);
        if (re_N == 1) break;
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                int data = q.front();
                q.pop();
                falling[i][j] = data;
            }
        }
        N /= 2;
    }

    cout << q.front();
    return 0;
}
