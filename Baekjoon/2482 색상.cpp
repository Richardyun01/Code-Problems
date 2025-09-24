/*
  �˰��� �з�: ���̳��� ���α׷���

  ���� ��� �� ����
  - ���� ��ȹ�� �迭 �ʱ�ȭ
    - dp[i][j]: i���� ����ȯ���� j���� ���� �����ϴ� ����� ��
    - 0�� �����ϴ� ���� 1����
    - 1�� �����ϴ� ���� i����
  - ��ȭ�� ����
    - dp[i-2][j-1]: j-1���� �������� �� ���� ���� �����ϴ� ���
    - dp[i-1][j]: ���� ���� �������� �ʰ� �Ѿ�� ���
*/

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000003;
int main() {
    int N, K;
    cin >> N >> K;
    if (K > N / 2) {
        cout << 0;
        return 0;
    }
    int dp[1001][1001] = {0,};
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MOD;
        }
    }
    cout << (dp[N-1][K]+dp[N-3][K-1]) % MOD;
    return 0;
}
