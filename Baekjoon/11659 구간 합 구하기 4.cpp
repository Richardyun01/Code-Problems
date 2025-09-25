/*
  알고리즘 분류: 누적 합

  접근 방법 및 구현
  - i와 j를 입력받은 후 for 문으로 범위를 탐색해서 값을 구하면 시간 초과 발생
  - 누적 합을 사용: 행렬에 대해서 각 인덱스까지의 구간의 합을 구하기
  - N개의 수를 저장하면서 특정 인덱스의 누적 합은 이전 인덱스의 누적 합 - 현재 인덱스의 값
  - 특정 범위의 누적 합은 최대값 누적 합 - (최소값-1) 누적 합
*/

#include<iostream>
#define endl '\n'
using namespace std;
int N, M;
int n[100001], ps[100001] = {0,};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    // 누적합 계산
    for (int i = 1; i <= N; i++) {
        cin >> n[i];
        ps[i] = ps[i-1] + n[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b, sum = 0;
        cin >> a >> b;
        cout << (ps[b] - ps[a-1]) << endl;
    }
    return 0;
}