/*
  �˰��� �з�: �ڷ� ����, ���հ� ��, �ؽø� ����� ���հ� ��

  ���� ��� �� ����
  - �迭�� �뷮�� �ʹ� ���� �����ϱ� ������ ��� �Ұ�
  - ���� ���� Ž���� �Ҹ� -> ���� unordered_map�� ����ؾ� ��
*/

#include<iostream>
#include<algorithm>
#include<unordered_map>
#define endl '\n'
using namespace std;
unordered_map<string, string> site_password;
int N, M;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        site_password.insert(make_pair(tmp1, tmp2));
    }
    // for (pair<string, string> elem : site_password) {
    //     cout << elem.first << ' ' << elem.second << endl;
    // }
    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        // Ž��
        auto iter = site_password.find(tmp);
        if (iter != site_password.end()) {
            cout << iter->second << endl;
        }
    }
    return 0;
}