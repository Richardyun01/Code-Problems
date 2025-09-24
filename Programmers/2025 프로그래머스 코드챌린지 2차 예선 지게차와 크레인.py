# ���� ��� �� ����
# - ������ ��û�� �� ���� ���� ������ �͸� �����ϹǷ� BFS�� �̿��� ���� ���Ÿ� �����ؾ� ��
# - �ܺο� ����� ��ĭ�� BFS�� ǥ��
# - ���ÿ� �����ؾ� ���� ���Ű� �Ͼ�� ����
# - �׵θ��� �ִ� ��� �ٷ� �ܺο� ���� �����Ƿ� ���� ���
# - �ܺο� ����� ��ĭ�� ������ ���� ��ǥ�� ���� Ž��
# - ũ���� ��û�� ���� �����̹Ƿ� �ܼ� ��ȸ�� ��� ����

from collections import deque

def solution(storage, requests):
    n, m = len(storage), len(storage[0])
    grid = [list(row) for row in storage]
    dirs = [(-1,0),(1,0),(0,-1),(0,1)]
    
    def in_bounds(x, y):
        return 0 <= x < n and 0 <= y < m
    # ���ĺ� ���� ����
    def remove_crane(ch):
        for i in range(n):
            for j in range(m):
                if grid[i][j] == ch:
                    grid[i][j] = '*'
    # �ܺο� ����� ���ĺ��� ����
    def remove_fork(ch):
        # �ܺο� ����� ��ĭ�� bfs�� ǥ��
        vis = [[False]*m for _ in range(n)]
        q = deque()
        
        # �׵θ��� ��ĭ�� ���������� �߰�
        for i in range(n):
            for j in (0, m-1):
                if grid[i][j] == '*' and not vis[i][j]:
                    vis[i][j] = True
                    q.append((i, j))
        for j in range(m):
            for i in (0, n-1):
                if grid[i][j] == '*' and not vis[i][j]:
                    vis[i][j] = True
                    q.append((i, j))
        # ��ĭ�� ��������
        while q:
            x, y = q.popleft()
            for dx, dy in dirs:
                nx, ny = x+dx, y+dy
                if in_bounds(nx, ny) and not vis[nx][ny] and grid[nx][ny] == '*':
                    vis[nx][ny] = True
                    q.append((nx, ny))
        # ���� ��� ����
        to_remove = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] != ch:
                    continue
                # �׵θ��� �ִ� ���
                if i == 0 or i == n-1 or j == 0 or j == m-1:
                    to_remove.append((i, j))
                    continue
                # �ܺο� ����� ��ĭ�� ������ ���
                for dx, dy in dirs:
                    ni, nj = i+dx, j+dy
                    if in_bounds(ni, nj) and grid[ni][nj] == '*' and vis[ni][nj]:
                        to_remove.append((i, j))
                        break
        for x, y in to_remove:
            grid[x][y] = '*'
    # ���ĺ� ���� ���� �۾�
    for req in requests:
        ch = req[0]
        if len(req) == 2:
            remove_crane(ch)
        else:
            remove_fork(ch)
    answer = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '*':
                answer += 1
    return answer