/*
  알고리즘 분류: 자료 구조, 집합과 맵, 해시를 사용한 집합과 맵

  접근 방법 및 구현
  - 배열은 용량을 너무 많이 차지하기 때문에 사용 불가
  - 벡터 쌍은 탐색에 불리 -> 따라서 unordered_map를 사용해야 함
*/

#include<iostream>
#include<algorithm>
#include<unordered_map>
#define endl '\n'
using namespace std;
unordered_map<string, string> site_password;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        site_password.insert(make_pair(tmp1, tmp2));
    }
    // for (pair<string, string> elem : site_password) {
    //     cout << elem.first << ' ' << elem.second << endl;
    // }
    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        // 탐색
        auto iter = site_password.find(tmp);
        if (iter != site_password.end()) {
            cout << iter->second << endl;
        }
    }
    return 0;
}