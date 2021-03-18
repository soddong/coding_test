from collections import deque
n, m = map(int, input().split())
arr = [[0 for _ in range(m)] for _ in range(n)]
q = deque()

for i in range(n):
    tmp = input()
    for j in range(m):
        arr[i][j] = int(tmp[j])

dist = [[-1 for _ in range(m)] for _ in range(n)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# start
dist[0][0] = 1
q.append((0, 0))
while q:
    x, y = q.popleft()
    # print(x, y, dist[x][y])
    # print(x, y)
    for i in range(4):
            if 0 <= x+dx[i] < n and 0 <= y+dy[i] < m:
                if dist[x+dx[i]][y+dy[i]] == -1 and arr[x+dx[i]][y+dy[i]] == 1:
                    q.append((x+dx[i], y+dy[i]))
                    dist[x+dx[i]][y+dy[i]] = dist[x][y] + 1
                    # print(x, y, dist[x][y], x+dx[i], y+dy[i], dist[x+dx[i]][y+dy[i]])

print(dist[n-1][m-1])
