#include <iostream>
#include <stack>
#include <vector>
#include <sstream>


using namespace std;

int rowCheck();
int columnCheck();


int main()
{
    int rows;
    int columns;
    cin >> rows >> columns;
    vector<string> tiles(rows);
    //메인에서 타일 배치를다 받아야지
    //각 Row를 Stack<Char>로 받는거지
    // rows개 만큼의 stack을 저장할 곳이 필요해해
    for(int i = 0; i<rows; i++){
        cin >> tiles[i];
    }
    
    int cnt = 0;
    for (int j = 0; j < rows ; j++){
        bool bar = false;
        
        for(int i = 0; i < columns ; i++){
            if (tiles[j][i] == '-'){
                if (bar == false){
                    cnt++;
                }
                bar = true;
            }else {
                bar = false;
            }
            
            
        }
    }
    //cout << "가로바 개수 : " << cnt << "개"<<endl;
    
    for (int j = 0; j < columns ; j++){
        bool bar = false;
        
        for(int i = 0; i < rows ; i++){
            if (tiles[i][j] == '|'){
                if (bar == false){
                    cnt++;
                }
                bar = true;
            }else {
                bar = false;
            }
            
            
        }
    }
    //cout << "최종 개수 : " << cnt << "개"<<endl;
    cout << cnt;
    return 0;
}