def solution(n, computers):
    answer = 0
    checked = [0] * n
    def dfs(x, y):
        nonlocal checked
        nonlocal computers
        nonlocal answer
        checked[x] = 1
        for z in range(n):
            if (checked[z] == 0) and (computers[y][z] == 1):
                dfs(y, z)
    for i in range(n):
        for j in range(n):
            if (checked[j] == 0) and (computers[i][j] == 1):
                dfs(i, j)
                answer += 1
    print(answer)
    return answer

N = int(input())
A = [[int(x) for x in input().split()] for y in range(N)]
solution(N, A)