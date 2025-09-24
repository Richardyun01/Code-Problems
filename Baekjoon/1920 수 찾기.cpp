/*
  �˰��� �з�: �ڷᱸ��, ����, �̺� Ž��, ���հ� ��, �ؽø� ����� ���հ� ��

  ���� ��� �� ����
  - ���Ʈ���� ��� �� �ð����⵵�� �ִ� O(N^2)�� �Ǳ� ������ �ð� �ʰ�
  - N���� ���� log N�� �ð����⵵�� ���� ���� Ž�� �Լ� binary_search�� ���
  - �̶� ������ ������ ����Ǿ�� ��
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int N, M;
vector<int> A;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    A.clear();
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    // ���� ����
    sort(A.begin(), A.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        if (binary_search(A.begin(), A.end(), tmp)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}