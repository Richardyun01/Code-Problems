# 접근 방법 및 구현
# - 바구니는 LIFO 구조이므로 스택을 사용하면 됨(파이썬의 리스트가 스택)
# - 스택에서 끝에 동일한 두 개의 인형이 쌓였을 시 폭발 -> 이때 인형 2개 소멸
# - 체크 종료 시 해당 과정에서는 더 볼 필요가 없으므로 break

def solution(board, moves):
    stk = []
    answer = 0
    for i in moves:
        for j in range(len(board)):
            if board[j][i-1] != 0:
                stk.append(board[j][i-1])
                board[j][i-1] = 0
                # 인형이 2개 이상 쌓였을 때 끝 2개가 동일 시 폭발
                if len(stk) > 1:
                    if stk[-1] == stk[-2]:
                        # 인형 2개 소멸
                        stk.pop(-1)
                        stk.pop(-1)
                        answer += 2
                break
    return answer