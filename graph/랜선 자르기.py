# [이분탐색] 랜선 자르기 - 1654번
k, n = map(int, input().split())
arr = [0 for _ in range(k)]
for i in range(k):
    arr[i] = int(input())

left = 1
right = max(arr)
answer = 0

while left <= right:
    mid = int((left + right)/2)
    cnt = 0
    for i in range(k):
        cnt += arr[i]//mid
    # print(cnt)
    if cnt >= n:
        if answer < mid:
            answer = mid
        left = mid + 1
    elif cnt < n:
        right = mid - 1
print(answer)