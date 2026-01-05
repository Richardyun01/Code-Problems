# Postorder 배열을 통해 서브트리의 부모 노드를 뒤에서 앞으로 접근
# 전개 순서: LRV(V->R->L)
# 현재 서브트리의 부모 노드를 알아내고 inorder 구간에서 해당 노드를 기준으로 좌측 서브트리와 우측 서브트리를 알아낸 다음 postorder의 인덱스를 차감해야 함
# 좌/우 서브트리 구성을 위해 재귀함수를 호출해야 함
# V->R->L 순서를 맞추기 위해 우측 재귀함수 호출 뒤 좌측 재귀함수 호출
# 구성 후 재귀함수 호출한 결과값을 반환
# Python에서 내부 변수 및 함수 이용 시 self 붙이기 필수
class Solution:
    # postorder의 인덱스를 나타내는 정수 초기화
    # 전역 변수로서 사용되므로 __init__에서 초기화해야 함
    def __init__(self):
        self.postorderIdx = 0

    # 서브트리 생성 재귀함수
    def recursion(self, inorder, postorder, inorderStart, inorderEnd) -> Optional[TreeNode]:
        # null인 경우: inorder의 시작이 끝보다 큰 경우
        if inorderStart > inorderEnd:
            return None
        # 트리의 노드 생성
        node = TreeNode(postorder[self.postorderIdx])
        for i in range(inorderStart, inorderEnd+1):
            # 현재 inorder 값와 postorder의 인덱스에서의 값이 동일할 경우
            if inorder[i] == postorder[self.postorderIdx]:
                # postorder의 인덱스 감소
                self.postorderIdx -= 1
                # 우측 서브트리 구성
                node.right = self.recursion(inorder, postorder, i+1, inorderEnd)
                # 좌측 서브트리 구성
                node.left = self.recursion(inorder, postorder, inorderStart, i-1)
                break
        return node

    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # postorder의 마지막에서 시작(트리의 root)
        self.postorderIdx = len(postorder) - 1
        return self.recursion(inorder, postorder, 0, len(inorder)-1)