from collections import deque

MAX = 200001
n, m = map(int, input().split())

checked = [0]*MAX
dist = [0]*MAX
f = [0]*MAX
q = deque()

q.append(n)
checked[n] = True


# dist[next] 가 최소인 놈
while q:
    curr = q.popleft()
    for next in [curr+1, curr-1, curr*2]:
        if 0 <= next < MAX and checked[next] == False:
            q.append(next)
            checked[next] = True
            dist[next] = dist[curr] + 1
            f[next] = curr


history = []
i = m
history.append(str(m))
while i != n:
    i = f[i]
    history.append(str(i))
print(dist[m])
print(" ".join(reversed(history)))