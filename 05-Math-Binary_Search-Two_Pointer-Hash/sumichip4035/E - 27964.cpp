#include <set>
#include <string>
#include <iostream>
using namespace std;
void fast_io(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(void)
{
    fast_io();
    set<string> s;
    int n=0;
    string check = "Cheese";
    cin >> n;
    while(n--)
    {
        string str;
        cin >> str;
        if(str.find(check,str.size()-6)!=string::npos)
            s.insert(str);
    }
    if(s.size() >= 4)
        cout << "yummy";
    else
        cout << "sad";
}