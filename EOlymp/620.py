n = int(input())

ways = [[0 for last in range(10)] for size in range(n + 1)]
for last in range(10):
    ways[1][last] = int(last not in [0, 8])

prev_list = [[4, 6], [6, 8], [7, 9], [4, 8], [0, 3, 9], [], [0, 1, 7], [2, 6], [1, 3], [2, 4]]

for size in range(2, n + 1):
    for last in range(10):
        for prev in prev_list[last]:
            ways[size][last] += ways[size - 1][prev]

print(sum(ways[n]))
