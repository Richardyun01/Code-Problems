/*
  알고리즘 분류: 이분 탐색, 가장 긴 증가하는 부분 수열: o(n log n)

  접근 방법 및 구현
  - LIS 배열 유지
    - lis 배열을 유지하며 현재까지 LIS의 마지막 원소보다 크면 축가하고 작거나 같으면 적절한 위치에 갱신
    - lower_bound()로 삽입 위치를 검색
      - lis 배열에 num을 삽입할 위치를 검색
      - 적절한 위치에 값이 있으면 업데이트하여 최적 LIS를 유지
  - 이전 원소 추적
    - 실제 LIS를 복원하기 위해 prev 배열로 LIS를 구성하는 인덱스를 저장
      - prev[i]에는 현재 LIS 원소의 이전 원소 인덱스를 저장
      - 마지막 원소부터 역추적해 실제 LIS 수열을 구함
    - 최종 LIS를 역추적해 정답 구함
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> lis, lis_indice;
    vector<int> prev(N, -1);
    for (int i = 0; i < N; i++) {
        int num = A[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int pos = it - lis.begin();
        if (it == lis.end()) {
            lis.push_back(num);
            lis_indice.push_back(i);
        } else {
            *it = num;
            lis_indice[pos] = i;
        }
        if (pos > 0) {
            prev[i] = lis_indice[pos-1];
        }
    }
    int lis_len = lis.size();
    cout << lis_len << endl;
    vector<int> ans(lis_len);
    int idx = lis_indice[lis_len-1];
    for (int i = lis_len - 1; i >= 0; i--) {
        ans[i] = A[idx];
        idx = prev[idx];
    }
    for (int i = 0; i < lis_len; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}