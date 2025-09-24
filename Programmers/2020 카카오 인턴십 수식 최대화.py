# 접근 방법 및 구현
# - 연산자 우선순위 경우의 수가 6종류고 수식의 길이도 짧으므로 브루트포스를 사용
# - 파싱으로 수식에서 숫자와 연산자를 분리
# - permutations로 연산자 우선순위 6가지를 모두 생성
# - 각 우선순위마다 새로 파싱을 수행해 수식에서 수와 연산자를 하나씩 줄여가며 수식 계산 수행
# - 절댓값은 따로 저장하고 max로 최대 획득

from itertools import permutations

def solution(expression):
    # 수 및 부호 파싱
    def parse(expr):
        nums, ops, cur = [], [], ""
        for ch in expr:
            # 숫자면 현재 숫자에 이어붙임
            if '0' <= ch <= '9':
                cur += ch
            # 연산자면 수/연산자 리스트에 추가
            else:
                nums.append(int(cur))
                ops.append(ch)
                cur = ""
        # 마지막 숫자
        nums.append(int(cur))
        return nums, ops
    
    values = []
    for priority in permutations(['*', '+', '-'], 3):
        # 연산자와 피연산자 저장
        operands, operators = parse(expression)
        for op in priority:
            while op in operators:
                # i번째 연산자는 i번째와 i+1번째 피연산자에 대한 계산 수행
                i = operators.index(op)
                if op == '*':
                    v = operands[i] * operands[i+1]
                elif op == '+':
                    v = operands[i] + operands[i+1]
                else:
                    v = operands[i] - operands[i+1]
                # 연산자/피연산자 리스트 업데이트
                operands[i] = v
                operands.pop(i+1)
                operators.pop(i)
            values.append(operands[0])
    return max(abs(v) for v in values)