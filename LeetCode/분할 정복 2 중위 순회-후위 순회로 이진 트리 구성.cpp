// Postorder 배열을 통해 서브트리의 부모 노드를 뒤에서 앞으로 접근
// 전개 순서: LRV(V->R->L)
// 현재 서브트리의 부모 노드를 알아내고 inorder 구간에서 해당 노드를 기준으로 좌측 서브트리와 우측 서브트리를 알아낸 다음 postorder의 인덱스를 차감해야 함
// 좌/우 서브트리 구성을 위해 재귀함수를 호출해야 함
// V->R->L 순서를 맞추기 위해 우측 재귀함수 호출 뒤 좌측 재귀함수 호출
// 구성 후 재귀함수 호출한 결과값을 반환
class Solution {
public:
    int postorderIdx = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIdx = postorder.size()-1;
        return recursion(inorder, postorder, 0, inorder.size()-1);
    }
    TreeNode* recursion(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd) {
        if (inorderStart > inorderEnd) {
            return NULL;
        }
        // new로 생성해서 동적 포인터 할당을 가능하게 함
        TreeNode* node = new TreeNode(postorder[postorderIdx]);
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (inorder[i] == postorder[postorderIdx]) {
                postorderIdx--;
                // 포인터에서 접근 중이므로 '.' 대신 '->'로 접근
                node->right = recursion(inorder, postorder, i+1, inorderEnd);
                node->left = recursion(inorder, postorder, inorderStart, i-1);
                break;
            }
        }
        return node;
    }
};