/*
  알고리즘 분류: 트리, 분할 정복, 재귀

  접근 방법 및 구현
  - 재귀함수
    - 포스트오더의 마지막 값을 루트로 사용
    - 루트 노드의 인덱스로 서브트리 구분
    - 좌측 서브트리 재귀 호출
    - 우측 서브트리 재귀 호출
    - 범위를 벗어날 시 종료
*/

#include <bits/stdc++.h>
using namespace std;
int idx[100001];
int inorder[100001];
int postorder[100001];
void preorder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;
    int root = idx[postorder[post_end]];
    int left_size = root - in_start;
    int right_size = in_end - root;
    cout << inorder[root] << ' ';
    preorder(in_start, root-1, post_start, post_start+left_size-1);
    preorder(root+1, in_end, post_start+left_size, post_end-1);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> postorder[i];
    }
    preorder(1, n, 1, n);
    return 0;
}