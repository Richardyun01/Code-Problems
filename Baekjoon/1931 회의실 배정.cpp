/*
  �˰��� �з�: �׸��� �˰���, ����

  ���� ��� �� ����
  - �׸��� �˰���: ���õ� ȸ���� ���� �ð��� ���ݱ����� ���� �ð����� ���ų� ũ�� �����ϰ� ���� �ð��� ����
  - �׸��� �˰����� �۵��ϱ� ���ؼ��� ȸ�� ����� ������ �ʼ�
  - ȸ�� ����� ���۰� �� ��� �����ؾ� �ϹǷ� 2���� �����ؾ� �� -> �� �ð��� ��� ���� �Լ��� �����Ͽ� ����
*/

#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
vector<pair<int, int>> conf;
int N, res = 0, end_time = 0;
// ���� �ð��� �������� ����
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        conf.push_back(make_pair(a, b));
    }
    // first�� second�� �����ϰ� ����
    sort(conf.begin(), conf.end());
    sort(conf.begin(), conf.end(), compare);
// for (int i = 0; i < N; i++) {
//     cout << conf[i].first << ' ' << conf[i].second << endl;
// }
    for (int i = 0; i < N; i++) {
        // ���� ���� �ð��� ���� ���� �ð����� Ŭ ��
        if (conf[i].first >= end_time) {
// cout << "conf[" << i <<"].first: " << conf[i].first << endl;
            // ���� �ð��� �������� �ѱ�
            end_time = conf[i].second;
// cout << "end_time: " << end_time << endl;
            res += 1;
        }
    }
    cout << res << endl;
    return 0;
}