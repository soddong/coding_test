# 10816 - 숫자카드2
from collections import Counter

n = int(input())
cards_n = list(map(int, input().split()))
cnt_cards = Counter(cards_n)

m = int(input())
targets_m = list(map(int, input().split()))
cards_n = sorted(cards_n)

for target in targets_m:
    if target in cnt_cards:
        cnt = cnt_cards[target]
        print(cnt)
    else: print(0)
