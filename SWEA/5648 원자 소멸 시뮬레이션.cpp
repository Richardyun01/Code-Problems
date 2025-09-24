/*
  ���� ��� �� ����
  - �켱 ������ ������ �����ϴ� ����ü���� ����
  - ���� ��ġ���� ������ ���� ǥ���ϴ� ��ǥ �迭�� �ʿ�
  - ���ڵ��� �� ���� ���� �̵�/���� ���� �� ���� �� �� ������ �浹 ������ ����ؾ� ��
  - ���� ������ �Է¹ް� ���� ��ǥ�� �����ϱ� ���ؼ� ū ���� ���ϰ� ����
  - ������ ���� ��ġ �ʱ�ȭ �� ������ ������ ��ġ�� ������ ����(���� ���)
  - ���� ��ġ �������� �ڽŰ� �ٸ� �� = �� ���ڰ� ���ÿ� �����Ͽ� ���� ������ �� �浹 �߻����� ����
  - ���� ���ڸ� ���� ��Ƽ� �ٽ� ����
  - ��� ���ڰ� �Ҹ��� ������ ���� �ݺ�(�浹 �� �ϴ� ���ڴ� ������ ����� �Ҹ�)
*/

#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
struct Atom {
    int x;
    int y;
    int dir;
    int K;
};
int N;
int map[4001][4001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<Atom> A;
int move_atoms() {
    int res = 0;
    while (!A.empty()) {
        int size = (int)A.size();
        for (int i = 0; i < size; i++) {
            // ���� ��ġ �ʱ�ȭ
            map[A[i].y][A[i].x] = 0;
            int dir = A[i].dir;
            int nx = A[i].x + dx[dir];
            int ny = A[i].y + dy[dir];
            // ������ ����� ���
            if (nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {
                A[i].K = 0;
                continue;
            }
            A[i].x = nx;
            A[i].y = ny;
            // ���� ��ġ ������ ����
            map[ny][nx] += A[i].K;
        }
        for (int i = 0; i < size; i++) {
            if (A[i].K == 0) continue;
            int x = A[i].x;
            int y = A[i].y;
            // ���� ��ġ�� ���� �������� �ڽŰ� �ٸ� ��: �浹 �߻�
            if (map[y][x] != A[i].K) {
// cout << "x: " << A[i].x << " y: " << A[i].y << endl;
                res += map[y][x];
                map[y][x] = 0;
                A[i].K = 0;
            }
// if (res != 0) cout << "res: " << res << endl;
        }
        // ���� ���ڸ� �ٽ� ����
        vector<Atom> tmp_vector;
        tmp_vector.assign(A.begin(), A.end());
        A.clear();
        for (int i = 0; i < (int)tmp_vector.size(); i++) {
            if (tmp_vector[i].K != 0) {
                A.push_back(tmp_vector[i]);
            }
        }
    }
    return res;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
		    Atom atom;
		    cin >> atom.x >> atom.y >> atom.dir >> atom.K;
		    // ���� ��ǥ ����
		    atom.x += 1000;
		    atom.y += 1000;
		    atom.x *= 2;
		    atom.y *= 2;
		    A.push_back(atom);
		}
		int ans = move_atoms();
		cout << '#' << tc << ' ' << ans << endl;
	}
	return 0;
}