#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <algorithm>
using namespace std;

struct homework {
    int deadline,grade;
    
    homework() { }
    homework(int d,int g) : deadline(d),grade(g) { }
};

bool cmp (homework &h1,homework &h2){
    return h1.grade > h2.grade;
}

int n,d,g,ans,last_day;
bool visited[1001];
vector<homework> v;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> d >> g;
        v.push_back(homework(d,g));
        last_day = max(last_day,d);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    memset(visited, false, sizeof(visited));
    ans = 0;
    
    for(int day=last_day; day>=1; day--){
        for(int i=0; i<v.size(); i++){
            if(!visited[i] && v[i].deadline >= day){
                ans += v[i].grade;
                visited[i] = true;
                break;
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}