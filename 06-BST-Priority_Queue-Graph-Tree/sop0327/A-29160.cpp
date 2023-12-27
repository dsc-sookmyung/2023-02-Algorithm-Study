// 시간 초과

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Player
{
    int position;
    int value;
};

bool comparePlayers(const Player &a, const Player &b)
{
    return a.value > b.value;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<Player> players(n);

    for (int i = 0; i < n; i++)
    {
        cin >> players[i].position >> players[i].value;
    }

    sort(players.begin(), players.end(), comparePlayers);

    vector<int> selectedPlayers(12, -1);

    for (int year = 1; year <= k; year++)
    {
        for (int i = 0; i < n; i++)
        {
            int position = players[i].position;
            if (selectedPlayers[position] == -1)
            {
                selectedPlayers[position] = i;
            }
        }

        for (int i = 1; i <= 11; i++)
        {
            if (selectedPlayers[i] != -1)
            {
                players[selectedPlayers[i]].value = max(0, players[selectedPlayers[i]].value - 1);
            }
        }
        fill(selectedPlayers.begin(), selectedPlayers.end(), -1);
    }

    int totalValue = 0;
    for (int i = 0; i < n; i++)
    {
        totalValue += players[i].value;
    }

    cout << totalValue << endl;

    return 0;
}