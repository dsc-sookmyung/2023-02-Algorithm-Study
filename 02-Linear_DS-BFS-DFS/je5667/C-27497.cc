#include <iostream>
#include <deque>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    deque<string> deq;
    stack<string> keys;
    
    for(int i=0; i<n; i++){
        //cout << i + 1 << "번째 줄"<<endl;
        string first, second;
        cin >> first;
        
        if(first == "1"){
                cin >> second;
                deq.push_back(second);
                keys.push(first);
                
            //for (int o=0; o<deq.size(); o++){
            //    cout << deq[o];
            //}
            //cout << endl;
            
        }
        if(first == "2"){
                cin >> second;
                deq.push_front(second);
                keys.push(first);
            //for (int o=0; o<deq.size(); o++){
            //    cout << deq[o];
            //}
            //cout << endl;
        }
        if(first == "3" && deq.empty() != true && keys.empty() != true){
            //3
            if(keys.top() == "1"){
                deq.pop_back();
            } else if(keys.top() == "2"){
                deq.pop_front();
            }
            //if (!keys.empty()){
                keys.pop();    
            //}
            
        }
    }
    if(deq.empty()){
        cout << 0;
    }else {
        for (int i=0; i<deq.size(); i++){
            cout << deq[i];
        }
    }
    return 0;
}