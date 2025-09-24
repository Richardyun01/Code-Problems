# ���� ��� �� ����
# - �پ��� ������ ���ڿ� ó�� �Լ� ��� ������ �䱸�ϴ� ����
# - lower()/upper(): ���ڿ� ���ĺ� �ҹ���/�빮�ڷ� ��ȯ
# - isalpha()/isdigit(): ���ڰ� ���ĺ�/�������� �Ǵ�
# - replace(): Ư�� ���ڿ��� �ٸ� ���ڿ��� ��ȯ
# - strip(): ���ڿ��� �Ǿյ� Ư�� ���ڸ� ����
# - lstrip()/rstrip(): ���ڿ��� �Ǿ�/�ǵ� Ư�� ���ڸ� ����
# - ���� ��ü�� ���ʴ�� �ܼ��ϰ� �ֱ⸸ �ϸ� ��

def solution(new_id):
    answer = ""
    # 1 �ҹ��� ġȯ
    new_id = new_id.lower();
    # 2 ���� ����
    for ch in new_id:
        if ch.isalpha() or ch.isdigit() or ch in ['-', '_', '.']:
            answer += ch
    # 3 .. ġȯ
    while '..' in answer:
        answer = answer.replace('..', '.')
    # 4 �յ� . ����
    answer = answer.strip('.')
    # 5 �� ���ڿ� ó��
    if len(answer) == 0:
        answer += 'a'
    # 6 ���ڿ� ���� ����
    tmp1 = ""
    if len(answer) >= 16:
        for i in range(0, 15):
            tmp1 += answer[i]
        answer = tmp1
    answer = answer.rstrip('.')
    # 7 2�� ���� ���ڿ� ó��
    if len(answer) == 1:
        answer += answer[0]
        answer += answer[0]
    elif len(answer) == 2:
        answer += answer[1]
    print(answer)
    return answer