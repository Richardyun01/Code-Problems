/*
  알고리즘 분류: 수학, 정수론, 유클리드 호제법

  접근 방법 및 구현
  - 유클리드 호제법: 최대공약수를 구하는 방법
    - 두 수 a, b가 주어졌을 때
    - b == 0이라면 a가 최대공약수가 되고 그렇지 않으면 b와 a%b의 최대공약수를 탐색
    - 이를 재귀적으로 반복
  - 최소공배수는 그냥 두 수를 곱하고 최대공약수로 나누면 됨
*/

#include<iostream>
#define endl '\n'
using namespace std;
int find_gcd(int a, int b) {
    if (b == 0) return a;
    else return find_gcd(b, a%b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, gcd, lcm;
    cin >> n >> m;
    int r;
    gcd = find_gcd(n, m);
    lcm = n*m/gcd;
    cout << gcd << endl << lcm << endl;
    return 0;
}