# 접근 방법 및 구현
# - bin(): 10진수를 2진수로 변환, 앞에 0b가 붙으므로 [2:]를 사용해 잘라내야 함
# - 브루트포스는 사용 불가 - 가능한 경우가 10^15이므로 시간복잡도 초과
# - 가능한 경우의 수
#   - 0이 중간에 위치한 경우: 변환 시 0이 오른쪽으로 이동
#   - 변환 시 모두 1로 차있는 경우: 앞에 0을 넣고 오른쪽으로 이동
#   - 0이 우측에 위치한 경우: 1을 더하면 됨
# - 0인 비트가 존재하면 0 비트 좌측은 그대로, 10으로 0과 1의 위치를 바꾸고 2칸 뒤의 우측 부분은 그대로
# - 0인 비트가 없으면 좌측이 10으로 바뀌고 나머지는 그대로
# - int()는 N진수를 10진수로 변환 가능

def solution(numbers):
    answer = []
    for n in numbers:
        tmp = bin(n)[2:]
        # print(tmp)
        if tmp[-1] == '0':
            answer.append(n+1)
        else:
            idx = 0
            for i in range(len(tmp)-1, -1, -1):
                if tmp[i] != '1':
                    idx = i
                    break
            if idx == 0:
                tmp = '10' + tmp[1:]
                # print(tmp)
                answer.append(int(tmp, 2))
            else:
                tmp = tmp[:idx] + '10' + tmp[idx+2:]
                # print(tmp)
                answer.append(int(tmp, 2))
            # print(tmp)
    return answer

# print(solution([2,7]))