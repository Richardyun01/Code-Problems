/*
  �˰��� �з�: ������, ���� ���� ����

  ���� ��� �� ����
  - �� a, b, c, d�� ����
  - ���� ab�� ac�� ccw�� ���� ab�� ad�� ccw�� ��ȣ�� �ݴ��� �� ���� ������ ����
  - ���� ab�� ac�� ccw�� ���� ab�� ad�� ccw�� ��ȣ�� ���� �� ���� ������ �������� ����
*/

#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
};
int ccw(Point a, Point b, Point c) {
    int ret = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
    if (ret > 0) return 1;
    else if (ret < 0) return -1;
    else return 0;
}
int main() {
    Point p[4];
    for (int i = 0; i < 4; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    if (ccw(p[0], p[1], p[2])*ccw(p[0], p[1], p[3]) < 0) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}