# [이분탐색] 2110 - 공유기설치
n, m = map(int, input().split())
houses = [0 for _ in range(n)]
for i in range(n):
    houses[i] = int(input())
houses = sorted(houses)

# 이분탐색: 거리
left = 1
right = (houses[n-1] - houses[0])
answer = 0
while left <= right:
    # if m == 2:
    #     answer = right
    #     break
    # 1 2 4 8 9
    mid = int((left + right)/2)
    # print(left, right, mid)
    cnt = 0
    s = 0
    e = 0
    while e < n:
         # print(s, e, houses[e]-houses[s])
         if houses[e]-houses[s] >= mid:
             cnt += 1
             s = e
             e = e + 1
         else: e += 1
    cnt += 1
    if cnt >= m:
        if answer < mid : answer = mid
        left = mid+1
    elif cnt < m:
        right = mid-1
print(answer)
