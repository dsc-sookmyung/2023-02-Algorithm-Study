
#include <iostream>
#include <deque>

using namespace std;
int check();

int main(){
    int n ;
    n = check();
    return 0;
}


int check(){
    int n;
    cin >> n;
    std::deque<int> deq;
    
    for(int i=1; i <= n; i++){
        deq.push_front(i);
    }
    int len = deq.size();
    for(int i=0; i<len-1; i++){
        deq.pop_back();
        int output = deq.back();
        deq.pop_back();
        deq.push_front(output);
    }
    cout << deq.back() << endl;
    return deq.back();
}
