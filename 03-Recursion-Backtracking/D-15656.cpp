// 혜린님 코드 + 주석

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
vector<int> v;
vector<int> ans;

// 재귀 함수: 현재까지 선택한 숫자들을 포함하는 조합을 생성
void n_m(int num)
{
    // 조합의 크기가 m에 도달하면 결과 출력
    if (num == m)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    // 현재 가능한 모든 숫자에 대해 조합 생성
    for (int i = 0; i < v.size(); i++)
    {
        // 현재 숫자를 조합에 추가
        ans.push_back(v[i]);

        // 다음 숫자를 선택하도록 재귀 호출
        n_m(num + 1);

        // 현재 숫자를 조합에서 제거 (백트래킹)
        ans.pop_back();
    }
}

int main()
{
    // 입력: n과 m을 받음
    cin >> n >> m;

    // 입력받은 크기만큼 벡터 v를 생성하고 값을 입력
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // 벡터 v를 정렬
    sort(v.begin(), v.end());

    // 재귀 함수 호출을 통해 조합 생성 및 출력
    n_m(0);

    return 0;
}