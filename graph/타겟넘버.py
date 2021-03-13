def solution(numbers, target):
    answer = 0
    cnt = 0
    def dfs(x, oper, sum):
        nonlocal cnt
        tmp = numbers[x] * oper
        if x == len(numbers) - 1:
            if (sum + tmp) == target:
                cnt += 1
        else:
            sum += tmp
            dfs(x + 1, 1, sum)
            dfs(x + 1, -1, sum)
    dfs(0, 1, 0)
    dfs(0, -1, 0)
    answer = cnt
    return answer


a = list(map(int, input().split()))
n = int(input())
solution(a, n)