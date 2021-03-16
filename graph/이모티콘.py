from collections import deque
s = int(input())
MAX = 2001
# 1 -> s개 만들기
# dist : 시간의 최소값
# curr-1 -> dist[curr] + 1, curr*2 -> dist[curr] +2
dist = [[-1 for _ in range(MAX)] for _ in range(MAX)]
checked = [0]*MAX
q = deque()

q.append((1, 0))
dist[1][0] = 0

while q:
    now, copy = q.popleft()
    if dist[now][now] == -1:
        q.append((now, now))
        dist[now][now] = dist[now][copy] + 1

    if 0 < now-1:
        if dist[now-1][copy] == -1 :
            q.append((now - 1, copy))
            dist[now -1][copy] = dist[now][copy] + 1

    if now + copy < MAX :
        if dist[now+copy][copy] == -1 :
            q.append((now+copy, copy))
            dist[now+copy][copy] = dist[now][copy] + 1

answer = MAX
for i in range(MAX):
    if dist[s][i] != -1 and answer > dist[s][i]:
        answer = dist[s][i]
print(answer)