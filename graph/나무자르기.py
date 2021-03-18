# [이분탐색] 2805 - 나무자르기
n, m = map(int, input().split())
trees = list(map(int, input().split()))

left = 1
right = max(trees)
answer = 0
while left <= right:
    mid = int((left + right)/2)
    cnt = 0
    trigger = 0
    for tree in trees:
        if tree - mid > 0:
            cnt += tree - mid
        if cnt >= m:
            trigger = 1
            break

    if trigger == 1:
        if mid > answer:
            answer = mid
        left = mid + 1
    elif trigger == 0:
        right = mid - 1
print(answer)