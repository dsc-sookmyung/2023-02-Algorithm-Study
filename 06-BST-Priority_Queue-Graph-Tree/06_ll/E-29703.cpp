#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int N, M;
vector<vector<char>> mapGrid;
vector<vector<bool>> visitedBefore, visitedAfter;
pair<int, int> start;

class Penguin {
public:
    int x, y, fishCnt, time;

    Penguin(int x=0, int y=0, int fishCnt=0, int time=0) : x(x), y(y), fishCnt(fishCnt), time(time) {}
};

int solve();
int BFS();
bool ableCheck(int nextX, int nextY, const vector<vector<bool>>& isVisited);
void input_data();

int main() {
    input_data();
    cout << solve() << endl;

    return 0;
}

int solve() {
    int ans = BFS();
    return (ans != -1) ? ans : -1;
}

int BFS() {
    int ans = -1;
    queue<Penguin> que;
    que.push(Penguin(start.first, start.second, 0, 0));

    visitedBefore.assign(N, vector<bool>(M, false));
    visitedAfter.assign(N, vector<bool>(M, false));

    visitedBefore[start.first][start.second] = true;

    while (!que.empty()) {
        Penguin nowCoor = que.front();
        que.pop();

        for (int i = 0; i < 4; ++i) {
            int nextX = nowCoor.x + ((i % 2 == 0) ? (i == 0 ? -1 : 1) : 0);
            int nextY = nowCoor.y + ((i % 2 == 1) ? (i == 1 ? 1 : -1) : 0);

            if (nowCoor.fishCnt >= 1) {
                if (!ableCheck(nextX, nextY, visitedAfter)) {
                    continue;
                }
                char next = mapGrid[nextX][nextY];
                if (next == 'F') {
                    que.push(Penguin(nextX, nextY, nowCoor.fishCnt + 1, nowCoor.time + 1));
                    visitedAfter[nextX][nextY] = true;
                } else if (next == 'H') {
                    ans = nowCoor.time + 1;
                    return ans;
                } else {
                    que.push(Penguin(nextX, nextY, nowCoor.fishCnt, nowCoor.time + 1));
                    visitedAfter[nextX][nextY] = true;
                }
            } else {
                if (!ableCheck(nextX, nextY, visitedBefore)) {
                    continue;
                }
                char next = mapGrid[nextX][nextY];
                if (next == 'F') {
                    que.push(Penguin(nextX, nextY, nowCoor.fishCnt + 1, nowCoor.time + 1));
                    visitedBefore[nextX][nextY] = true;
                } else if (next == 'H') {
                    que.push(Penguin(nextX, nextY, nowCoor.fishCnt, nowCoor.time + 1));
                    visitedBefore[nextX][nextY] = true;
                } else {
                    que.push(Penguin(nextX, nextY, nowCoor.fishCnt, nowCoor.time + 1));
                    visitedBefore[nextX][nextY] = true;
                }
            }
        }
    }

    return ans;
}

bool ableCheck(int nextX, int nextY, const vector<vector<bool>>& isVisited) {
    return 0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !isVisited[nextX][nextY] && mapGrid[nextX][nextY] != 'D';
}

void input_data() {
    cin >> N >> M;
    mapGrid.assign(N, vector<char>(M));

    for (int x = 0; x < N; ++x) {
        for (int y = 0; y < M; ++y) {
            cin >> mapGrid[x][y];
            if (mapGrid[x][y] == 'S') {
                start = {x, y};
            }
        }
    }
}
