/*
  알고리즘 분류: 구현, 정렬

  접근 방법 및 구현
  - 비교해야 할 변수가 3개이므로 구조체를 정의해 비교를 쉽게 함
  - 동점일 시 같은 순위를 줘야 하므로 별도의 벡터를 정의해 순위를 따로 저장
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
struct Cons {
    int cont;
    int a;
    int b;
    int c;
};
bool compare(Cons t1, Cons t2) {
    if (t1.a != t2.a) return t1.a > t2.a;
    if (t1.b != t2.b) return t1.b > t2.b;
    return t1.c > t2.c;
}
int main() {
    cin >> N >> K;
    vector<Cons> con(N);
    for (int i = 0; i < N; i++) {
        cin >> con[i].cont >> con[i].a >> con[i].b >> con[i].c;
    }
    sort(con.begin(), con.end(), compare);
    // 순위 조정: 동점이면 같은 순위 주기 위한 벡터
    vector<int> rank(N);
    rank[0] = 1;
    for (int i = 1; i < N; i++) {
        // 직전 원소와 점수가 같으면 같은 순위
        if (con[i].a == con[i-1].a && con[i].b == con[i-1].b && con[i].c == con[i-1].c) {
            rank[i] = rank[i-1];
        } else {
            rank[i] = i+1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (con[i].cont == K) {
            cout << rank[i];
            break;
        }
    }
    return 0;
}