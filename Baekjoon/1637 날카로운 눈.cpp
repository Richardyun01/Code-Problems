/*
  알고리즘 분류: 이분 탐색, 매개 분류 탐색

  접근 방법 및 구현
  - 이분 탐색으로 중간 값 mid 선택
  - 각 수열에서 mid 이하 원소 개수 계산 후 전체 합 계산
  - 합이 짝수일 시: 해당 정수가 mid보다 크므로 탐색 범위는 오른쪽
  - 합이 홀수일 시: 해당 정수가 mid보다 크므로 탐색 범위는 왼쪽
  - 해당 과정을 반복
*/

#include <bits/stdc++.h>
using namespace std;
#define long long ll
struct Item {
    int a, c, b;
};
int n, ans = -1;
Item arr[20000];
ll sol(ll mid) {
    if (mid == 0) return 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll num = 0;
        ll val = min((ll)arr[i].c, mid) - arr[i].a;
        num = val < 0 ? 0 : val / arr[i].b + 1;
        sum += num;
    }
    return sum;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].c >> arr[i].b;
    }
    ll left = 0, right = 2147483647;
    while (left <= right) {
        ll mid = (left+right) / 2;
        if (sol(mid) % 2 == 0) {
            left = mid+1;
        } else {
            ans = (int)mid;
            right = mid-1;
        }
    }
    if (ans == -1) cout << "NOTHING";
    else cout << ans << ' ' << sol(ans) - sol(ans-1);
    return 0;
}