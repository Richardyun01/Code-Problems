/*
  �˰��� �з�: ���̳��� ���α׷���

  ���� ��� �� ����
  - �ʱ�ȭ
    - dp[i][i] = 1 (���� 1�� �κ� ������ �׻� �Ӹ����)
    - dp[i][i+1] = 1 (�� ���� ���ӵ� ���� ������ �Ӹ����)
  - DP ���̺� ä���
    - dp[start][end]�� ä�� �� dp[start+1][end-1]�� true�� arr[start] == arr[end]�̸� dp[start][end] = true
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000;
int arr[MAX_N+1];
bool dp[MAX_N+1][MAX_N+1];
int main() {
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i][i] = true;
    }
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i+1]) dp[i][i+1] = true;
    }
    for (int len = 3; len <= N; len++) {
        for (int start = 1; start <= N-len+1; start++) {
            int end = start+len-1;
            if (arr[start] == arr[end] && dp[start+1][end-1]) {
                dp[start][end] = true;
            }
        }
    }
    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }
    return 0;
}