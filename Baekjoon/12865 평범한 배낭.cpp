/*
  �˰��� �з�: ���̳��� ���α׷���, �賶 ����

  ���� ��� �� ����
  - 0/1 �賶 ����
  - dp[i][j]�� ù i���� �������� ����� �� �賶�� �뷮�� j�� �� ���� �� �ִ� �ִ� ��ġ�� ����
  - i��° �������� �����ϴ� ���� ������ �� ���� ��츦 ��� ����Ͽ� ��ȭ�� �ۼ�
  - ���� �뷮 j�� �������� ���Ժ��� ũ�ų� ���� ���� �ش� ������ ���� ���� -> �� ū ���� ����
*/

#include <bits/stdc++.h>
using namespace std;
pair<int, int> object[101];
int dp[101][100001];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> object[i].first >> object[i].second;
    }
    for (int i = 1; i <= n; i++) {
        int weight = object[i-1].first;
        int value = object[i-1].second;
        for (int j = 0; j <= k; j++) {
            if (j >= weight) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
    return 0;
}