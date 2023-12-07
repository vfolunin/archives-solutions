from functools import cmp_to_key
from sys import stdin


def card_score(c):
    return '23456789TJQKA'.index(c)


def hand_score(h):
    h = ''.join(sorted(list(h), key=card_score))
    if h[0] == h[4]:
        return 6
    elif h[0] == h[3] or h[1] == h[4]:
        return 5
    elif h[0] == h[1] and h[2] == h[4] or h[0] == h[2] and h[3] == h[4]:
        return 4
    elif h[0] == h[2] or h[1] == h[3] or h[2] == h[4]:
        return 3
    elif h[0] == h[1] and (h[2] == h[3] or h[3] == h[4]) or h[1] == h[2] and h[3] == h[4]:
        return 2
    elif h[0] == h[1] or h[1] == h[2] or h[2] == h[3] or h[3] == h[4]:
        return 1
    else:
        return 0


def compare(a, b):
    a_score, b_score = hand_score(a[0]), hand_score(b[0])
    if a_score != b_score:
        return a_score - b_score

    for i in range(len(a[0])):
        a_score, b_score = card_score(a[0][i]), card_score(b[0][i])
        if a_score != b_score:
            return a_score - b_score

    return 0


pairs = [line.strip().split() for line in stdin]
for pair in pairs:
    pair[1] = int(pair[1])
pairs.sort(key=cmp_to_key(compare))

res = 0
for i in range(len(pairs)):
    res += pairs[i][1] * (i + 1)
print(res)
