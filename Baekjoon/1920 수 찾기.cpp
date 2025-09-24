/*
  알고리즘 분류: 자료구조, 정렬, 이분 탐색, 집합과 맵, 해시를 사용한 집합과 맵

  접근 방법 및 구현
  - 브루트포스 사용 시 시간복잡도가 최대 O(N^2)이 되기 때문에 시간 초과
  - N보다 작은 log N의 시간복잡도를 가진 이진 탐색 함수 binary_search를 사용
  - 이때 벡터의 정렬이 선행되어야 함
*/

#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
int N, M;
vector<int> A;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    A.clear();
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    // 벡터 정렬
    sort(A.begin(), A.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        if (binary_search(A.begin(), A.end(), tmp)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}