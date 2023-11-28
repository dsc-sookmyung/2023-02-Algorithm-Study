// 혜린님 코드 + 주석

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // 시험의 수 입력
    cin >> N;

    // 5개의 레벨에 대한 각 문제 수 입력
    vector<int> level(5);
    for (int i = 0; i < 5; ++i)
    {
        cin >> level[i];
    }

    // 시험의 난이도와 소요 시간을 저장할 pair의 벡터 생성
    vector<pair<int, int>> exam;
    for (int i = 0; i < N; ++i)
    {
        int k, t;
        // 시험의 난이도와 소요 시간 입력
        cin >> k >> t;
        exam.push_back({k, t});
    }

    // 시험을 난이도 순으로 정렬
    sort(exam.begin(), exam.end());

    // 결과값 및 이전 레벨, 소요 시간, 첫 번째 시험을 통과했는지 여부 초기화
    int res = 0;
    int before_level = 1;
    int before_time = 0;
    bool first_clear = true;

    // 각 시험에 대한 처리
    for (auto [i, j] : exam)
    {
        // 해당 레벨의 문제가 남아있는 경우
        if (level[i - 1] > 0)
        {
            // 결과값에 소요 시간 추가 및 해당 레벨의 문제 수 감소
            res += j;
            level[i - 1] -= 1;

            // 첫 번째 시험을 통과한 경우
            if (first_clear)
            {
                first_clear = false;
            }
            // 이전 시험과 같은 레벨인 경우, 소요 시간만큼 추가
            else if (before_level == i)
            {
                res += (j - before_time);
            }
            // 이전 시험과 다른 레벨인 경우, 60분 추가
            else if (before_level != i)
            {
                res += 60;
            }

            // 이전 레벨과 소요 시간 갱신
            before_level = i;
            before_time = j;
        }
    }

    // 최종 결과 출력
    cout << res << endl;

    return 0;
}
