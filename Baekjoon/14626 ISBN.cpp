/*
  �˰��� �з�: ����, ����, ���Ʈ���� �˰���, ��Ģ����

  ���� ��� �� ����
  - ���ǿ� �°� ��� ���� ���� ���ϴ� ������ ����
  - *�� �ο��ؾ� �ϴ� ����ġ�� sum�� ä�� �������� ���� ���� ����
  - *�� ��ġ�� Ȧ���� �� ���� 3���� ����� ����� �� Ʋ�� ����� ����
  - ��ⷯ ������ ����ؼ� ����ؾ� ��: 3�� ���� 7�� ���Ͽ� ��ⷯ �ظ� ���ϱ�
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
        // *�� ����ġ
        int w = (tmp1 % 2 == 0) ? 1 : 3;
        // ä���� �� ������
        int need = (10 - (sum % 10)) % 10;
        if (w == 1) ans = need;
        else ans = (need * 7) % 10; 
        }
    }
    cout << ans << endl;
    return 0;
}