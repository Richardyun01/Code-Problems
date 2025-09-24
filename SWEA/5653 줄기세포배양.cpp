/*
  ���� ��� �� ����
  - ��� ��� ũ��: �ʱ� 50 + ��� �ð� 300 = �ִ� 350
  - �����¿�� 300/2=150��ŭ �����ϹǷ� (150, 150)���� �ʱ� ��� ��� ���� ����
  - �Է¹��� �� != 0: �ٱ⼼���̹Ƿ� �켱���� ť�� ����
  - ������� ���� ������� ���� ������ 4�������� ���� ���� �� ����, ������ ������ ���� �� ����
  - ��Ȱ��ȭ �ð�: t = 0, ���� �ð�: 1�� ���� t = -1
  - Ȱ��ȭ�� ������ �״� �ð�: -(����� ��ġ) �ð� -> dead ����
  - K �ð� ���� ����ִ� ������ ��: len - dead
*/

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
struct Cell {
    int x;
    int y;
    int X;
    int t;  // ���� ���� �����
};
struct cmp {
    bool operator()(Cell a, Cell b) {
        return a.X < b.X;
    }
};
int N, M, K;
int tmp, len, dead, x, y, nx, ny, X;
// �ʱ� ��� ���
int map[350][350];
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
vector<Cell> cells;
priority_queue<Cell, vector<Cell>, cmp> activation;
// Ȯ��: ���� ���
void bfs() {
    while (!activation.empty()) {
        // ������� ū ������� ���� ������
        x = activation.top().x;
        y = activation.top().y;
        X = activation.top().X;
// cout << "x, y, X: " << x << ' ' << y << ' ' <<  X << endl;
        activation.pop();
        // 4�������� ����
        for (int i = 0; i < 4; i++) {
            nx = x+dr[i];
            ny = y+dc[i];
            // ������ ���� �� ���� ���
            if (map[nx][ny] == 0) {
                map[nx][ny] = X;
                cells.push_back({nx, ny, X, X});
                len++;
            }
        }
// cout << "len: " << len << endl;
    }
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
	    memset(map, 0, sizeof(map));
	    cells.clear();
	    dead = 0;
		cin >> N >> M >> K;
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < M; j++) {
	            cin >> tmp;
	            map[150+i][150+j] = tmp;
	            if (tmp != 0) {
	                cells.push_back({150+i, 150+j, tmp, tmp});
	            }
	        }
	    }
	    len = cells.size();
	    while (K > 0) {
	        K--;
	        for (int i = 0; i < len; i++) {
	            cells[i].t--;
	            // ��Ȱ��ȭ ����:Ȱ��ȭ
	            if (cells[i].t == -1) activation.push(cells[i]);
	            // Ȱ��ȭ ����: ����
	            if (cells[i].t == -cells[i].X) dead++;
// cout << cells[i].t << " dead: " << i+1 << ": " << dead << endl;
	        }
	        bfs();
	    }
	    cout << '#' << tc << ' ' << len-dead << endl;
	}
	return 0;
}
?