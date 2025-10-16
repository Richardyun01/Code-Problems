/*
  알고리즘 분류: 그리디 알고리즘, 정렬

  접근 방법 및 구현
  - 그리디 알고리즘: 선택된 회의의 시작 시간이 지금까지의 종료 시간보다 같거나 크면 선택하고 종료 시간을 갱신
  - 그리디 알고리즘이 작동하기 위해서는 회의 목록의 정렬이 필수
  - 회의 목록의 시작과 끝 모두 정렬해야 하므로 2번을 정렬해야 함 -> 끝 시간의 경우 따로 함수를 정의하여 정렬
*/

#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
vector<pair<int, int>> conf;
int N, res = 0, end_time = 0;
// 종료 시간을 기준으로 정렬
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        conf.push_back(make_pair(a, b));
    }
    // first와 second를 완전하게 정렬
    sort(conf.begin(), conf.end());
    sort(conf.begin(), conf.end(), compare);
// for (int i = 0; i < N; i++) {
//     cout << conf[i].first << ' ' << conf[i].second << endl;
// }
    for (int i = 0; i < N; i++) {
        // 현재 시작 시간이 이전 종료 시간보다 클 시
        if (conf[i].first >= end_time) {
// cout << "conf[" << i <<"].first: " << conf[i].first << endl;
            // 종료 시간을 다음으로 넘김
            end_time = conf[i].second;
// cout << "end_time: " << end_time << endl;
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}