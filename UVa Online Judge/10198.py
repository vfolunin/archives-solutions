from sys import stdin

ways = [[0 for length in range(1001)] for n in range(1001)]
ways[0][0] = 1

for n in range(1001):
    for length in range(1, 1001):
        ways[n][length] += 2 * ways[n - 1][length - 1]
        if n >= 2:
            ways[n][length] += ways[n - 2][length - 1]
        if n >= 3:
            ways[n][length] += ways[n - 3][length - 1]

ways = [sum(row) for row in ways]

for line in stdin:
    print(ways[int(line)])
