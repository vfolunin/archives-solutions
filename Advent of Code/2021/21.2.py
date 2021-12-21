from functools import lru_cache
from sys import stdin


@lru_cache(maxsize=None)
def rec(pos, score, player):
    if score[0] >= 21:
        return 1
    if score[1] >= 21:
        return 0

    res = 0
    for die_sum, factor in [(3, 1), (4, 3), (5, 6), (6, 7), (7, 6), (8, 3), (9, 1)]:
        next_pos = list(pos)
        next_pos[player] = (next_pos[player] + die_sum) % 10
        next_score = list(score)
        next_score[player] += next_pos[player] + 1
        res += factor * rec(tuple(next_pos), tuple(next_score), player ^ 1)
    return res


pos = tuple(int(line.split()[-1]) - 1 for line in stdin)
print(rec(pos, (0, 0), 0))
