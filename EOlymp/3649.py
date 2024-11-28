target_size = int(input())
max_value = int(input())

ways = [[0 for value in range(max_value + 1)] for size in range(target_size + 1)]
for last in range(max_value + 1):
    ways[1][last] = 1

for size in range(2, target_size + 1):
    for last in range(max_value + 1):
        for prev in range(last + 1):
            ways[size][last] += ways[size - 1][prev]

print((max_value + 1) ** target_size - 2 * sum(ways[target_size]) + (max_value + 1))