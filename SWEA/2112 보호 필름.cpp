/*
  ���� ��� �� ����
  - ��� ���� ������ Ư���� ���� ���� K�� �̻� ���������� �����ؾ� ��
  - �๰�� ������ ���� ������ �� ������ ����� ������ ��ġ�� ���� -> ���� ���
  - Ư�� ���� ������ �� �ش� ���� A�� B�� ������� ����
  - ������ ������ �๰�� �������� �� ������ Ž�� ���� X
  - �๰ ���� Ƚ���� K�� �̻��� �� Ž�� ���� X
*/

#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int D, W, K, res;
int map[21][21];
int c_map[21][21];
bool Select[21];
int compare_min(int a, int b) {
    if (a < b) return a;
    return b;
}
// �ʸ��� ���� �˻縦 ����ϴ��� Ȯ����
bool check(int arr[][21]) {
    for (int i = 0; i < W; i++) {
        // ��ǰ A, B, ���� ����
        int a_cnt = 0;
        int b_cnt = 0;
        bool flag = false;
        // ���� ���� �˻�
        for (int j = 0; j < D; j++) {
            if (arr[j][i] == 0) {
                b_cnt = 0;
                a_cnt++;
            } else {
                a_cnt = 0;
                b_cnt++;
            }
            // ���ӵ� K���� ������ �ش� ���� �հ�
            if (a_cnt == K || b_cnt == K) {
                flag = true;
                break;
            }
        }
        // �� ���̶� ������ �� ���հ�
        if (flag == false) return false;
    }
// cout << "Col pass" << endl;
    return true;
}
// �� ��ǰ ó�� �Ǵ� ���� ����
void make_visit(int idx, int value, bool T) {
    // ��ǰ ó��
    if (T == true) {
        for (int i = 0; i < W; i++) {
            c_map[idx][i] = value;
        }
// cout << "Row " << idx << " set to " << value << endl;
    // ����
    } else {
        for (int i = 0; i < W; i++) {
            c_map[idx][i] = map[idx][i];
// cout << "Row " << idx << " restored" << endl;
        }
    }
}
void dfs(int idx, int cnt) {
    // ���� Ƚ���� K���� ũ�ų� �ּҰ� �̻��� �� �ߴ�
    if (cnt > K || cnt >= res) return;
    // �˻� ��� �� �ּҰ� ����
    if (check(c_map) == true) {
        res = compare_min(res, cnt);
// cout << "Passed: " << res << " cnt: " << cnt << endl;
        return;
    }
    // ��� ������ �� ���� �࿡ ��ǰ ����
    for (int i = idx; i < D; i++) {
        if (Select[i] == true) continue;
        Select[i] = true;
        // i��° �࿡ A/B ����
        for (int j = 0; j < 2; j++) {
            make_visit(i, j, true);
            dfs(i, cnt+1);
            make_visit(i, j, false);
        }
        // ��Ʈ��ŷ
        Select[i] = false;
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
	    res = 999999999;
	    memset(Select, false, sizeof(Select));
        cin >> D >> W >> K;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> map[i][j];
                c_map[i][j] = map[i][j];
            }
        }
        if (check(map) == true || K == 1) {
            res = 0;
        } else {
            dfs(0, 0);
        }
        cout << '#' << tc << ' ' << res << endl;
	}
	return 0;
}
?