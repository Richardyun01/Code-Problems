/*
  알고리즘 분류: 구현, 자료구조, 문자역, 파싱, 덱

  접근 방법 및 구현
  - 파싱: 문자열 전체를 읽은 다음 임시 값을 정의한 뒤 해당 값에 (현재 글자-'0')과 현재 임시 값*10을 곱한 값을 대입하는 것을 반복
  - 이를 ','가 나올 때까지 반복하고 완료되면 그 수를 x에 집어넣음
  - R 작업(뒤집기): reverse()를 사용할 시 n만큼의 작업이 추가되므로 전체 시간복잡도가 O(n^2)가 되어 시간 초과가 발생함
  - 대신 bool 플래그를 세우고 나중에 출력할 때만 플래그에 따라 거꾸로 출력하면 됨
  - D 작업(제거): x를 배열로 정의할 시 앞에서 지우는 것이 불가능, 벡터로 정의할 시 erase를 사용해야 하는데 n만큼의 작업이 추가되므로 전체 시간복잡도가 O(n^2)가 되어 시간 초과가 발생함
  - 대신 deque를 사용하면 앞에서 지우는 작업이 1이 됨, 추가로 bool 플래그에 따라 앞 또는 뒤의 지우기가 가능해짐
*/

#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        string p, arr;
        int n;
        deque<int> x;
        bool check = true;
        cin >> p >> n >> arr;
        int tmp = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '[' || arr[i] == ']') continue;
            if (arr[i] == ',') {
                x.push_back(tmp);
                tmp = 0;
            } else {
                tmp = (arr[i]-'0')+tmp*10;
            }
        }
        if (tmp != 0) {
            x.push_back(tmp);
        }
        bool rev = false;
        for (char c : p) {
            if (c == 'R') {
                rev = !rev;
            } else if (c == 'D') {
                if (x.empty()) {
                    check = false;
                    break;
                }
                if (!rev) {
                    x.pop_front();
                } else {
                    x.pop_back();
                }
            }
        }
        if (check == true) {
            cout << "[";
            if (!rev) {
                for (int i = 0; i < x.size(); i++) {
                    if (i == x.size()-1) {
                        cout << x[i];
                    } else {
                        cout << x[i] << ',';
                    }
                }
            } else {
                for (int i = x.size()-1; i >= 0; i--) {
                    if (i == 0) {
                        cout << x[i];
                    } else {
                        cout << x[i] << ',';
                    }
                }
            }
            cout << "]" << endl;
        } else {
            cout << "error" << endl;
        }
    }
    return 0;
}