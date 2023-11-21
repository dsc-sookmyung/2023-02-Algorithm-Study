#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 9

int N,M;
int first[MAX];
int arr[MAX];

void dfs(int k) { 
    if(k==M) { 
        for(auto i =0;i<M;i++)
            cout << arr[i] << " "; 
        cout << "\n";
    }else { 
        for(auto i=0; i<N;i++) {
            arr[k]=first[i]; 
            dfs(k+1); 
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
        cin >> first[i];
    
    sort(first,first+N); 

    dfs(0);
}
