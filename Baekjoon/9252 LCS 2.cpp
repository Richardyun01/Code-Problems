/*
  �˰��� �з�: ���̳��� ���α׷���, ���ڿ�

  ���� ��� �� ����
  - dp ���̺� �ʱ�ȭ: dp[i][j]�� s1�� ó�� i���ڿ� s2�� ó�� j���� ������ LCS ���̸� ����
  - DP ���̺� ä���
    - �� ���ڿ��� ���ڰ� ������ �밢�� ���� ���� ���� 1�� ����
    - �� ���ڿ��� ���ڰ� �ٸ��� ����/���� �� �� ū ������ ����
  - LCS ���ڿ� ����: DP ���̺��� �ڿ������� �����Ͽ� LCS ���ڿ��� ������ �� ���ڿ��� ������ �ùٸ��� ���
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] << endl;
    if (dp[n][m] == 0) return 0;
    int i = n, j = m;
    string lcs;
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs.push_back(s1[i-1]);
            i--;
            j--;
        } else {
            if (dp[i-1][j] >= dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs;
    return 0;
}