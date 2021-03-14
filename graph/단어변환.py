from collections import deque

def check(cur, tar):
    cnt = 0
    for i in range(len(cur)):
        if cur[i] != tar[i]:    cnt += 1
    if cnt == 1 : return 1
    return 0

def solution(begin, target, words):
    answer = 0

    v = dict()
    q = deque()
    q.append((begin, 0))
    v[begin] = True

    while q:
        cur, l = q.popleft()

        for word in words:
            if check(word, cur) and word not in v:
                q.append((word, l+1))
                v[word] = True
                if word == target:
                    answer = l+1
    print(answer)
    return answer

b = input()
t = input()
ws = list(input().split())
solution(b, t, ws)