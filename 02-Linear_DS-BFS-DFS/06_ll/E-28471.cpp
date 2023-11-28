#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1, -1, -1, 1, 0, 1, 0 };
int dy[] = { 0,  1, -1, 1, -1,-1, 1 };

void dfs(vector<vector<char>>& board, int x, int y) {
    board[x][y] = 'V';

    for (int k = 0; k < 7; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size() && board[nx][ny] == '.') {
            dfs(board, nx, ny);
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N));
    pair<int, int> start;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'F') {
                start = { i, j };
            }
        }
    }

    
    dfs(board, start.first, start.second);

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'V') {
                count++;
            }
        }
    }

    cout << count - 1 << endl;
    return 0;
}
