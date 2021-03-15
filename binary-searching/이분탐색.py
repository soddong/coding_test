# 1920 - 수 찾기
n = int(input())
a = list(map(int, input().split()))
m = int(input())

a = sorted(a)
targets = list(map(int, input().split()))
for tar in targets:
    left = 0
    right = n-1
    trigger = 0
    while left <= right:
        mid = int((left + right)/2)
        if tar == a[mid]:
            trigger = 1
            break
        elif tar < a[mid]:
            right = mid -1
        elif tar > a[mid]:
            left = mid+1
    print(trigger)


