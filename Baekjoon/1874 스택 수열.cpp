/*
  알고리즘 분류: 자료 구조, 스택

  접근 방법 및 구현
  - 기호를 넣는 벡터를 따로 정의
  - 현재 값까지 수를 스택으로 쌓기, +를 벡터에 넣기
  - 현재 입력된 수와 스택의 맨 위에 있는 수가 동일하다면 pop, -를 벡터에 넣기, 동일하지 않다면 불가능한 것이므로 종료
*/

#include<iostream>
#include<vector>
#include<stack>
#define endl '\n'
using namespace std;
int main() {
    int n, cnt = 1;
    stack<int> stk;
    vector<char> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (cnt <= x) {
            stk.push(cnt);
            cnt += 1;
            v.push_back('+');
        }
        if (stk.top() == x) {
            stk.pop();
            v.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}