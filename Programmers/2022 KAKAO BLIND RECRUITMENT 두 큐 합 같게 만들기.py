# 접근 방법 및 구현
# - 합이 큰 쪽에서 pop을 해 다른 쪽에 추가하면 됨
# - queue의 길이가 길어질 수록 연산 소요 시간이 길어지므로 미리 변수로 만들어야 함
# - 최대 이동 횟수는 두 큐의 길이의 합+2
# - 최대 이동 횟수를 초과할 시 return을 하여 루프를 끊어야 함

from collections import deque

def solution(queue1, queue2):
    q1, q2 = deque(queue1), deque(queue2)
    sum1, sum2 = sum(q1), sum(q2)
    cnt = len(q1) + len(q2) + 2
    answer = 0
    # 두 큐의 합이 홀수면 정수로 같게 만들 수 없음
    if (sum1 + sum2) % 2 == 1:
        return -1
    # 같아질 때까지 반복
    while sum1 != sum2:
        if cnt > 0:
            # 합이 큰 쪽에서 원소를 pop해 다른 쪽에 추가
            if sum1 < sum2:
                i = q2.popleft()
                q1.append(i)
                sum1 += i
                sum2 -= i
                cnt -= 1
                answer += 1
            elif sum1 > sum2:
                i = q1.popleft()
                q2.append(i)
                sum1 -= i
                sum2 += i
                cnt -= 1
                answer += 1
        # 최대 이동 횟수 초과 시 return
        else:
            return -1
    return answer