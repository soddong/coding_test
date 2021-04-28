from itertools import combinations, permutations


# Initialize values
answer = 0
n = int(input())
stats = [[0 for j in range(n)] for i in range(n)]

# Input values
for i in range(n):
    stats[i] = list(map(int, input().split()))

# Deside members of team A, B for combination
teamA = list(combinations(range(n), int(n/2)))
for idx in range(len(teamA)):
    sumA = 0
    sumB = 0
    teamB = [k for k in range(n) if k not in teamA[idx]]
    # Find sumA, sumB and diff
    for x in teamA[idx]:
        for y in teamA[idx]:
            if x != y:
                sumA += stats[x][y]
    for x in teamB:
        for y in teamB:
            if x != y:
                sumB += stats[x][y]

    tmp = abs(sumA - sumB)

    # Find min value
    if idx == 0:
        answer = tmp
    elif tmp < answer:
        answer = tmp

print(answer)