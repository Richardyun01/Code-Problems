/*
  알고리즘 분류: 기하학, 선분 교차 판정

  접근 방법 및 구현
  - 점 a, b, c, d를 정의
  - 벡터 ab와 ac의 ccw와 벡터 ab와 ad의 ccw의 부호가 반대일 시 도형 내에서 교차
  - 벡터 ab와 ac의 ccw와 벡터 ab와 ad의 ccw의 부호가 같을 시 도형 내에서 교차하지 않음
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