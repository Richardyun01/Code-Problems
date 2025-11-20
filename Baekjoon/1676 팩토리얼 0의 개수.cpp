/*
  알고리즘 분류: 수학

  접근 방법 및 구현
  - 팩토리얼 값을 직접 구하는 것은 불가 -> 너무 커서 long long을 넘어감
  - 10으로 나눠서 0의 갯수를 세는 것은 부족함 -> 100, 1000으로 나누어 떨어질 수도 있기 때문
  - 10=5의 배수만 확인하면 되므로 n을 5, 25, 125로 각각 나누어 그 몫을 합산하면 됨
*/

#include<iostream>
using namespace std;
int main() {
    int n, cnt = 0;
    cin >> n;
    cnt += n / 5;
    cnt += n / 25;
    cnt += n / 125;
    cout << cnt;
    return 0;
}