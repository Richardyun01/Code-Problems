/*
  알고리즘 분류: 수학, 자료 구조, 조합론, 집합과 맵, 해시를 사용한 집합과 맵

  접근 방법 및 구현
  - 서로 다른 형의 쌍+탐색에 유리한 unordered_map을 사용
  - 각 형식(아래에서는 tmp2)의 갯수를 세기 위해 unordered_map에 string과 int를 담음
  - 전체 경우의 수는 (의상 종류+1)*(의상 종류+1)*... -1과 동일하므로 갯수를 세면 됨
*/

#include<iostream>
#include<unordered_map>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc, n;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n;
        int ans = 1;
        unordered_map<string, int> cnt;
        for (int j = 0; j < n; j++) {
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            cnt[tmp2]++;
        }
        for (auto &p : cnt) {
            ans *= p.second + 1;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}