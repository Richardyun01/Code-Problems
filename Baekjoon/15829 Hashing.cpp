/*
  알고리즘 분류: 구현, 문자열, 해싱

  접근 방법 및 구현
  - 문자열의 알파벳을 각각 수로 변환, 각각에 대해 31씩 곱하고 모두 더하기는 가장 기본적인 구조
  - 마지막에 m으로 나머지 구하기는 50점 짜리 발상
  - 매 단계마다 m으로 나머지를 구하여 크기 제한을 해야 함
  - r 또한 매 단계마다 증가시키되 m으로 나머지를 구해야 함
*/

#include<iostream>
#define endl '\n'
using namespace std;
typedef long long ll;
int alphabet_to_num(char c) {
    return c - 96;
}
int m = 1234567891;
// 1에서 시작하여 31씩 증가
long long r = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L;
    string hash_string;
    cin >> L >> hash_string;
    ll H = 0;
    for (int i = 0; i < L; i++) {
        // m으로 나눠서 크기 제한을 미리미리 해야 함
        H += (ll)(alphabet_to_num(hash_string[i]) * r) % m;
        // r도 m으로 나누어서 크기 제한을 해야 함
        r = (r*31) % m; 
    }
    cout << H % m << endl;
    return 0;
}