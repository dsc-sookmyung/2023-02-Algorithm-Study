#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, -1, -1, 1, 0, 1, 0}; // 7방향 이동에 대한 x축 변화 (W 제외)
int dy[] = { 0,  1, -1, 1, -1,-1, 1}; // 7방향 이동에 대한 y축 변화 (W 제외)

void printboard(vector<vector<char>>& board){
    cout<<"=============="<<endl;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j];
        }
        cout<<endl;
    }
    cout<<"=============="<<endl;
}

void dfs(vector<vector<char>>& board, int x, int y) {
    board[x][y] = 'V'; // 방문 표시
    //printboard(board);
    for (int k = 0; k < 7; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board.size() && board[nx][ny] == '.') {
            //cout << "going to : (" << nx << "," <<ny<<")"<<endl;
            dfs(board, nx, ny);
        }
    }
    
}

int main() {
    int N;
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N));
    pair<int, int> start; // 시작 지점 위치

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'F') {
                start = {i, j}; // 시작 지점 위치 저장
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
    //F 까지 V 표시가 되었으므로 - 1
    cout << count - 1 << endl;
    return 0;
}
