# 접근 방법 및 구현
# - 문자열 회전(슬라이싱)을 위해 2개를 이어붙임
# - 모든 회전 문자열을 생성하여 각 회전에 대해 올바른 괄호 문자열인지 검사
# - 짝이 맞지 않으면 스택에 넣고 비어있을 때만 옳은 문자열

def solution(s):
    answer = 0
    # 문자열을 회전시킬 수 있도록 2배로 만들기
    circle = s*2
    for i in range(len(s)):
        # 현재 위치에서 길이만큼 문자열 추출
        sub = circle[i:i+len(s)]
        stack = []
        for j in sub:
            # 스택이 비어있을 시
            if not stack:
                stack.append(j)
                continue
            # 스택의 마지막 원소와 현재 괄호가 짝을 이루는 경우 pop
            if ((stack[-1] == '(' and j == ')') or
                (stack[-1] == '{' and j == '}') or
                (stack[-1] == '[' and j == ']')):
                    stack.pop()
            # 짝이 안맞으면
            else:
                stack.append(j)
        if not stack:
            answer += 1
    return answer