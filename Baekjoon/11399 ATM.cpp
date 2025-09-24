/*
  알고리즘 분류: 그리디 알고리즘, 정렬

  접근 방법 및 구현
  - 시간의 합을 최소화하는 방법: 가장 작은 수를 가장 많이 더하고 가장 큰 수를 가장 적게 더하면 됨
  - 이는 배열을 정렬하고 순서대로 더하는 방법으로 구현 가능
  - 오름차순으로 정렬한 뒤 각각 인덱스 번호+1만큼 곱하고 더하면 됨
*/

#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
int N, sum = 0;
int P[1001];
// 내림차순으로 정렬
bool compare(int a, int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    // 내림차순으로 정렬
    sort(P, P+N, compare);
    // 합산
    for (int i = 0; i < N; i++) {
        sum += P[i] * (i+1);
    }
    cout << sum << endl;
    return 0;
}