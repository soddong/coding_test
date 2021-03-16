from collections import deque

MAX = 200001
n, m = map(int, input().split())

checked = [0 for _ in range(MAX)]
dist = [0 for _ in range(MAX)]
q = deque()

q.append(n)
checked[n] = True

while q:
    curr = q.popleft()
    for next in [curr+1, curr-1, curr*2]:
        if 0 <= next < MAX and checked[next] == False:
            checked[next] = True
            dist[next] = dist[curr] + 1
            q.append(next)
print(dist[m])