from collections import defaultdict
from sys import stdin

res = 0

for line in stdin:
    game, rounds = line.split(': ')
    min_count = defaultdict(int)

    for round in rounds.split('; '):
        for balls in round.split(', '):
            count, color = balls.split()
            min_count[color] = max(min_count[color], int(count))

    res += min_count['red'] * min_count['green'] * min_count['blue']

print(res)
