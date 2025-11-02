/*
  - 알고리즘 분류: 구현, 문자열
  
  - 접근 방법 및 구현
    - 각 글자들이 한 번 이상만 등장하면 되므로 각각에 대해 bool 변수 정의
    - 한 번이라도 등장하면 true로 전환, 모든 bool이 true면 YES 출력
    - 변수 명칭 헷갈리지 말 것
*/

#include<iostream>
#include<string>
using namespace std;
int main() {
    string str;
    cin >> str;
    if (str.size() < 5) {
        cout << "NO";
        return 0;
    }
    bool m = false, o = false, b = false, ii = false, s = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'M') {
            m = true;
            // cout << "M: true" << endl;
            continue;
        }
        if (str[i] == 'O') {
            o = true;
            // cout << "O: true" << endl;
            continue;
        }
        if (str[i] == 'B') {
            b = true;
            // cout << "B: true" << endl;
            continue;
        }
        if (str[i] == 'I') {
            ii = true;
            // cout << "I: true" << endl;
            continue;
        }
        if (str[i] == 'S') {
            s = true;
            // cout << "S: true" << endl;
            continue;
        }
    }
    if (m == true && o == true && b == true && ii == true && s == true) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}