# 접근 방법 및 구현
# - 전체적인 알고리즘은 지시사항대로 따라가면 됨
# - 균형대로 자르기 위해서는 최초로 균형이 맞는 지점에서 u를 더 이상 분리할 수 없을 때까지 반복
# - 올바른 균형 문자열인지 확인하기 위해서는 LIFO 방식대로 짝을 체크하면 됨
# - 문자열을 뒤집은 뒤 answer에 누적하면 차례대로 출력됨

def check(s):
    stack = []
    for i in s:
        # 스택 여는 괄호
        if i == '(':
            stack.append(i)
        else:
            if len(stack) == 0:
                # 스택이 비었는데 닫는 괄호가 올 시
                return False
            stack.pop()
    return True

def divide(s):
    left, right = 0, 0
    for i in range(len(s)):
        if s[i] == '(':
            left += 1
        else:
            right += 1
        if left == right:
            # 균형이 맞는 지점에서 자르면 u는 가장 짧은 올바른 괄호 문자열
            return s[:i+1], s[i+1:]

def solution(p):
    answer = ''
    if p == '':
        return ''
    u, v = divide(p)
    if check(u):
        return u + solution(v)
    else:
        answer += '('
        answer += solution(v)
        answer += ')'
        # 양 끝 제거해서 길이 2인 경우 빈 문자열로
        for s in u[1:len(u)-1]:
            # 각 문자를 뒤집어 새 문자열로 쌓기
            if s == '(':
                answer += ')'
            else:
                answer += '('
    return answer