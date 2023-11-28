#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int num,A,B;
    cin >> num;
    for (int i = 0 ; i<num ; i++){
        cin >> A>> B;
        cout<< A+B<<"\n";
    }
    return 0;
}