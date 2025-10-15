/*
  �˰��� �з�: ����, �ڷ� ����, ���շ�, ���հ� ��, �ؽø� ����� ���հ� ��

  ���� ��� �� ����
  - ���� �ٸ� ���� ��+Ž���� ������ unordered_map�� ���
  - �� ����(�Ʒ������� tmp2)�� ������ ���� ���� unordered_map�� string�� int�� ����
  - ��ü ����� ���� (�ǻ� ����+1)*(�ǻ� ����+1)*... -1�� �����ϹǷ� ������ ���� ��
*/

#include<iostream>
#include<unordered_map>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc, n;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n;
        int ans = 1;
        unordered_map<string, int> cnt;
        for (int j = 0; j < n; j++) {
            string tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            cnt[tmp2]++;
        }
        for (auto &p : cnt) {
            ans *= p.second + 1;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}