/*
  알고리즘 분류: 수학, 그리디 알고리즘, 문자열, 파싱

  접근 방법 및 구현
  - 식을 최소로 만드는 방법: - 뒤에 등장하는 +를 모두 -로 바꾸면 됨
  - - 뒤의 숫자들을 모두 빼면 됨
  - - 판별 기능은 먼저 나온 숫자를 빼지 않기 위해 반복문의 가장 뒤에 둠
*/

#include <iostream>
#include<string>
using namespace std;
int main() {
    string s;
    string num = "";
    bool check = false;
    int ans = 0;
    cin >> s;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '-' || s[i] == '+' || i == s.size()) {
            if (check == true) {
                ans -= stoi(num);
                num = "";
            } else {
                ans += stoi(num);
                num = "";
            }
        } else {
            num += s[i];
        }
        if (s[i] == '-') {
            check = true;
        }
    }
    cout << ans;
    return 0;
}