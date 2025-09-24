/*
  �˰��� �з�: �̺� Ž��, ���� �� �����ϴ� �κ� ����: o(n log n)

  ���� ��� �� ����
  - LIS �迭 ����
    - lis �迭�� �����ϸ� ������� LIS�� ������ ���Һ��� ũ�� �డ�ϰ� �۰ų� ������ ������ ��ġ�� ����
    - lower_bound()�� ���� ��ġ�� �˻�
      - lis �迭�� num�� ������ ��ġ�� �˻�
      - ������ ��ġ�� ���� ������ ������Ʈ�Ͽ� ���� LIS�� ����
  - ���� ���� ����
    - ���� LIS�� �����ϱ� ���� prev �迭�� LIS�� �����ϴ� �ε����� ����
      - prev[i]���� ���� LIS ������ ���� ���� �ε����� ����
      - ������ ���Һ��� �������� ���� LIS ������ ����
    - ���� LIS�� �������� ���� ����
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> lis, lis_indice;
    vector<int> prev(N, -1);
    for (int i = 0; i < N; i++) {
        int num = A[i];
        auto it = lower_bound(lis.begin(), lis.end(), num);
        int pos = it - lis.begin();
        if (it == lis.end()) {
            lis.push_back(num);
            lis_indice.push_back(i);
        } else {
            *it = num;
            lis_indice[pos] = i;
        }
        if (pos > 0) {
            prev[i] = lis_indice[pos-1];
        }
    }
    int lis_len = lis.size();
    cout << lis_len << endl;
    vector<int> ans(lis_len);
    int idx = lis_indice[lis_len-1];
    for (int i = lis_len - 1; i >= 0; i--) {
        ans[i] = A[idx];
        idx = prev[idx];
    }
    for (int i = 0; i < lis_len; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}