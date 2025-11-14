/*
  - 알고리즘 분류: 정렬, 두 포인터

  - 접근 방법 및 구현
    - 입력받은 뒤 우선 정렬
    - 최우측과 최좌측 두 개의 포인터 위치를 정의
    - 각각의 인덱스의 원소의 합이 X보다 작으면 left를 전진, 크면 right를 후진, 동일하면 left, right를 각각 전후진
*/

#include<iostream>
#include<algorithm>
using namespace std;
int N, X;
int a[100001];
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> X;
    sort(a, a+N);
    int left = 0, right = N-1;
    int ans = 0;
    while (left < right) {
        int tmp = a[left] + a[right];
        if (tmp < X) {
            left++;
        } else if (tmp > X) {
            right--;
        } else {
            left++;
            right--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}