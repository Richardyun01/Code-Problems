/*
  ���� ��� �� ����
  - �� Ȯ�� ��: �������� �����ϴ� ���� �����ϴ� ��츦 Ž��
  - �� Ȯ�� ��: �ϴ����� �����ϴ� ���� �����ϴ� ��츦 Ž��
  - ���� ���� 2 �̻��� ��� �Ǽ��� �Ұ�
  - �̹� ���θ� �Ǽ��� ���� �� �Ǽ��ؼ��� �ȵ�
  - �� Ȯ�� �Ϸ� �Ŀ��� �ʱ�ȭ�� �ʿ�
*/

#include<iostream>
#include<cmath>
using namespace std;
int n, len, map[21][21];
bool used[21][21];
// �� üũ
bool row_check(int i) {
    for (int j = 0; j < n-1; j++) {
        // cout << "[row_check] i=" << i << " j=" << j 
        //      << " map[i][j]=" << map[i][j] 
        //      << " map[i][j+1]=" << map[i][j+1] 
        //      << " used[i][j]=" << used[i][j] 
        //      << " used[i][j+1]=" << used[i][j+1] 
        //      << endl;
        // ���� ������ ���� ������ ��
        if (used[i][j+1]) continue;
        // ���� ���� 2 �̻�
        if (abs(map[i][j] - map[i][j+1]) >= 2) return false;
        if (map[i][j] == map[i][j+1]+1) {
            // ���ΰ� ������ ������ ���
            if (j+len >= n) return false;
            for (int k = j+1; k <= j+len-1; k++) {
                if (map[i][k] != map[i][k+1]) return false;
            }
            // �̹� ���ΰ� ���� ���
            for (int k = j+1; k <= j+len; k++) {
                if (used[i][k]) return false;
            }
            // ���� ǥ��
            for (int k = j+1; k <= j+len; k++) {
                used[i][k] = true;
            }
        }
    }
    for (int j = 0; j < n-1; j++) {
        // ���� ������ ���� ������ ��
        if (used[i][j+1]) continue;
        if (map[i][j] == map[i][j+1] - 1) {
            // ���ΰ� ������ ������ ���
            if (j+1-len < 0) return false;
            for (int k = j+1-len; k <= j-1; k++) {
                if (map[i][k] != map[i][k+1]) return false;
            }
            // �̹� ���ΰ� ���� ���
            for (int k = j+1-len; k <= j; k++) {
                if (used[i][k]) return false;
            }
            // ���� ǥ��
            for (int k = j+1-len; k <= j; k++) {
                used[i][k] = true;
            }
        }
    }
    return true;
}
bool col_check(int j) {
    for (int i = 0; i < n-1; i++) {
        // cout << "[col_check] j=" << j << " i=" << i 
        //      << " map[i][j]=" << map[i][j] 
        //      << " map[i+1][j]=" << map[i+1][j] 
        //      << " used[i][j]=" << used[i][j] 
        //      << " used[i+1][j]=" << used[i+1][j] 
        //      << endl;
        // ���� ������ ���� ������ ��
        if (used[i+1][j]) continue;
        // ���� ���� 2 �̻�
        if (abs(map[i][j] - map[i+1][j]) >= 2) return false;
        if (map[i][j] == map[i+1][j]+1) {
            // ���ΰ� ������ ������ ���
            if (i+len >= n) return false;
            for (int k = i+1; k <= i+len-1; k++) {
                if (map[k][j] != map[k+1][j]) return false;
            }
            for (int k = i+1; k <= i+len; k++) {
                if (used[k][j]) return false;
            }
            for (int k = i+1; k <= i+len; k++) {
                used[k][j] = true;
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        // ���� ������ ���� ������ ��
        if (used[i+1][j]) continue;
        if (map[i][j] == map[i+1][j] - 1) {
            // ���ΰ� ������ ������ ���
            if (i+1-len < 0) return false;
            for (int k = i+1-len; k <= i-1; k++) {
                if (map[k][j] != map[k+1][j]) return false;
            }
            for (int k = i+1-len; k <= i; k++) {
                if (used[k][j]) return false;
            }
            for (int k = i+1-len; k <= i; k++) {
                used[k][j] = true;
            }
        }
    }
    return true;
}
int process() {
    // ��� ������ ��
    int ret = 0;
    // ���� ���� Ȯ��
    for (int i = 0; i < n; i++) {
// cout << "row check " << i << ": " << row_check(i) << endl;
        if (!row_check(i)) continue;
        ret++;
    }
    // ���� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[i][j] = false;
        }
    }
    // ���� ���� Ȯ��
    for (int j = 0; j < n; j++) {
// cout << "col check " << j << ": " << col_check(j) << endl;
        if (!col_check(j)) continue;
        ret++;
    }
    return ret;
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int tc;
	int T;
	cin>>T;
	for(tc = 1; tc <= T; ++tc)
	{
		cin >> n >> len;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        cin >> map[i][j];
		    }
		}
		int res = process();
		cout << '#' << tc << ' ' << res << endl;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        map[i][j] = 0;
		    }
		}
		// ���� �ʱ�ȭ
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        used[i][j] = false;
		    }
		}
	}
	return 0;
}