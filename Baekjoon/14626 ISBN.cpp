/*
  알고리즘 분류: 수학, 구현, 브루트포스 알고리즘, 사칙연산

  접근 방법 및 구현
  - 조건에 맞게 모든 수의 합을 구하는 것으로 시작
  - *에 부여해야 하는 가중치와 sum을 채울 나머지를 각각 따로 정의
  - *의 위치가 홀수일 때 직접 3으로 나누어서 계산할 시 틀린 결과가 나옴
  - 모듈러 역원을 사용해서 계산해야 함: 3의 역원 7을 곱하여 모듈러 해를 구하기
*/

#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum = 0, ans = 0;
    int tmp1, tmp2;
    string isbn;
    cin >> isbn;
    for (int i = 0; i < 13; i++) {
        if (isbn[i] != '*') {
            if (i % 2 == 0) {
                sum += isbn[i]-'0';
            } else if (i % 2 == 1) {
                sum += (isbn[i]-'0')*3;
            }
        } else {
            tmp1 = i;
        }
    }
// cout << "sum: " << sum << endl;
    tmp2 = sum % 10;
    if (tmp2 == 0) {
        ans = 0;
    } else {
        // *의 가중치
        int w = (tmp1 % 2 == 0) ? 1 : 3;
        // 채워야 할 나머지
        int need = (10 - (sum % 10)) % 10;
        if (w == 1) ans = need;
        else ans = (need * 7) % 10; 
        }
    }
    cout << ans << endl;
    return 0;
}