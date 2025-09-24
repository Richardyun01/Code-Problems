# ���� ��� �� ����
# - bin(): 10������ 2������ ��ȯ, �տ� 0b�� �����Ƿ� [2:]�� ����� �߶󳻾� ��
# - ���Ʈ������ ��� �Ұ� - ������ ��찡 10^15�̹Ƿ� �ð����⵵ �ʰ�
# - ������ ����� ��
#   - 0�� �߰��� ��ġ�� ���: ��ȯ �� 0�� ���������� �̵�
#   - ��ȯ �� ��� 1�� ���ִ� ���: �տ� 0�� �ְ� ���������� �̵�
#   - 0�� ������ ��ġ�� ���: 1�� ���ϸ� ��
# - 0�� ��Ʈ�� �����ϸ� 0 ��Ʈ ������ �״��, 10���� 0�� 1�� ��ġ�� �ٲٰ� 2ĭ ���� ���� �κ��� �״��
# - 0�� ��Ʈ�� ������ ������ 10���� �ٲ�� �������� �״��
# - int()�� N������ 10������ ��ȯ ����

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