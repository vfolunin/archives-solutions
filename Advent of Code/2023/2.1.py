from sys import stdin

max_count = { 'red': 12, 'green': 13, 'blue': 14 }
res = 0

for line in stdin:
    game, rounds = line.split(': ')
    ok = 1

    for round in rounds.split('; '):
        for balls in round.split(', '):
            count, color = balls.split()
            if int(count) > max_count[color]:
                ok = 0
                break

    if ok:
        res += int(game.split()[1])

print(res)
