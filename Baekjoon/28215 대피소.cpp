#include<iostream>
#include<cmath>
using namespace std;
int N, K;
int x[51], y[51];
// 대피소로 선정된 세 집
int dist(int i, int j, int k) {
    int dis = 0;
    for (int h = 0; h < N; h++) {
        dis = max(dis, min(min(abs(x[i]-x[h]) + abs(y[i]-y[h]), abs(x[j]-x[h]) + abs(y[j]-y[h])), abs(x[k]-x[h]) + abs(y[k]-y[h])));
    }
    return dis;
}
int main() {
    int min_dis = 1e9;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    // 모든 집을 대피소로 설정하고 최솟값 구하기
    if (K == 1) {
        for (int i = 0; i < N; i++) {
            min_dis = min(min_dis, dist(i, i, i));
        }
    // 가능한 두 집의 조합을 대피소로 설정하고 구하기
    } else if (K == 2) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                min_dis = min(min_dis, dist(i, j, i));
            }
        }
    // 가능한 세 집의 조합을 대피소로 설정하고 구하기
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    min_dis = min(min_dis, dist(i, j, k));    
                }
            }
        }
    }
    cout << min_dis;
    return 0;
}