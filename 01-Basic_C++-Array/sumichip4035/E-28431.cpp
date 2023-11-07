#include <iostream>
#include <vector>
using namespace std;


int main(){
    int num = 5;
    int a;
    std::vector<int> pairs; 

    for (int i=0; i<num ; i++){
        cin>> a;
        pairs.push_back(a);
        
    }
    for (int i = 0; i < pairs.size(); i++) {
        for (int j = i + 1; j < pairs.size(); j++) {
            if (pairs[i] == pairs[j]) {
                pairs.erase(pairs.begin() + j);
                pairs.erase(pairs.begin() + i);
                i--; 
                break;
            }
        }
    }

        cout <<  pairs[0];

    return 0;
}
    