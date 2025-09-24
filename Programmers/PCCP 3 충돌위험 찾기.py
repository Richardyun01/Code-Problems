/*
  ���� ��� �� ����
  - �� ��θ��� �̵� ������ �ùķ��̼�
  - 1�ʿ� �� ĭ�� ������ ������ (x, y, �ð�) Ʃ���� ������ ����Ʈ�� ���
  - ��� ��ο� ���� �ùķ��̼� ���� �� �� ��ο��� ������ ��ϵ��� second ����Ʈ�� ��ħ
  - Ʃ���� ��ü ����Ʈ���� �� �� �ߺ��Ǿ� ��Ÿ������ ���
  - Ư�� Ʃ���� ������ 2�� �̻��̸� �浹�� ����
*/

from collections import Counter

def solution(points, routes):
    def bfs(route):
        idx = 0
        pa = []
        for i in range(len(route) - 1):
            # ������� �������� ��ǥ
            sx, sy = spots[route[i]-1]
            ex, ey = spots[route[i+1]-1]
            # x ��ǥ ���߱�
            while sx != ex:
                pa.append((sx, sy, idx))
                if sx < ex:
                    sx += 1
                else:
                    sx -= 1
                idx += 1
            # y ��ǥ ���߱�
            while sy != ey:
                pa.append((sx, sy, idx))
                if sy < ey:
                    sy += 1
                else:
                    sy -= 1
                idx += 1
        pa.append((sx, sy, idx))
        return pa
    
    spots = [i for i in points]
    second = []
    # ��� ��ο� ���� �� ����� �ùķ��̼� ����� ����Ʈ�� �߰�
    for route in routes:
        second.extend(bfs(route))
    answer = 0
    tmp = Counter(second)
    # ���� Ƚ���� 2 �̻��� �� �浹 1 ����
    for i in tmp.values():
        if i >= 2:
            answer += 1
    return answer