//시간초과
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    int position;
    int value;
};

bool comparePlayers(const Player &a, const Player &b) {
    return a.value > b.value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    scanf("%d %d", &N, &K);

    Player players[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &players[i].position, &players[i].value);
    }

    sort(players, players + N, comparePlayers);

    int selectedPlayerValues[11] = {0};

    for (int year = 1; year <= K; ++year) {
        // Select players in March
        for (int i = 0; i < N; ++i) {
            int position = players[i].position - 1;
            if (selectedPlayerValues[position] == 0) {
                selectedPlayerValues[position] = players[i].value;
                break;
            }
        }

        // Re-select players in November and decrement values
        for (int i = 0; i < 11; ++i) {
            if (selectedPlayerValues[i] == 0) {
                selectedPlayerValues[i] = players[i].value;
                break;
            }
        }
    }

    int totalValue = 0;
    for (int i = 0; i < 11; ++i) {
        totalValue += selectedPlayerValues[i];
    }

    printf("%d\n", totalValue);

    return 0;
}
